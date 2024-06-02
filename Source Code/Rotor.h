#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>

using namespace std;

/// @brief The maximum number of letters on a rotor.
#define NUM_LETTERS 26

/// @brief A class that represent a single rotor on the Enigma machine
class Rotor {
    private:
        /// @brief The current setting for the rotor.
        int currentSetting;

        /// @brief The initial setting for the rotor. Set when initializing a Rotor class (or when choosing the rotors to put in the machine IRL.) This value will be set to 1 if no value is provided when initializing.
        int initialSetting;

        /// @brief The number of times the rotor rotated.
        int rotateCount;

        /// @brief The name (identifier of the rotor).
        string identifier;

        /// @brief A pointer to a connected rotor. Set the `nullptr` if there is no rotor connected (i.e. last rotor to be passed through)
        Rotor* connectedRotor;

        /// @brief An array of strings holding all the letters in the alphabet (capital letters only!)
        const string letters[NUM_LETTERS] = {
            "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
        };

    public:
        Rotor(string identifier);
        Rotor(string identifier, int initialSetting);
        Rotor(string identifier, int initialSetting, Rotor* connectedRotor);
        ~Rotor();

        int getCurrentSetting() const;
        int getRotateCount() const;
        string getIdentifier() const;
        string getLetter(int index) const;

        void connectRotor(Rotor* connectedRotor);

        /// @brief Shift the current setting one step up. If the current setting is at 26, the next will be 1 (looping back from Z to A). This function replicate the physical action of rotating the rotor.
        void rotate();

        void print();
};

#endif