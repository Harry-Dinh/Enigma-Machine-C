#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>
#include <map>

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
        int rotationCount;

        /// @brief The name (identifier of the rotor).
        string identifier;

        /// @brief A pointer to a connected rotor. Set the `nullptr` if there is no rotor connected (i.e. last rotor to be passed through)
        Rotor* connectedRotor;

        /// @brief The wiring of the rotor, which basically convert a letter to a specific letter. The wiring should be assign randomly, but also have a way to initialize a rotor with specific wiring (i.e. for decryption.)
        map<char, char> wiring;

        /// @brief An array of strings holding all the letters in the alphabet (capital letters only!)
        const char LETTERS[NUM_LETTERS] = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
        };

    public:

        // CONSTRUCTORS

        Rotor();
        Rotor(string identifier);
        Rotor(string identifier, int initialSetting);
        Rotor(string identifier, int initialSetting, Rotor* connectedRotor);

        // DESTRUCTOR

        ~Rotor();

        /// @brief Get the letter (number in the alphabet) that the letter is currently on.
        int getCurrentSetting() const;

        /// @brief Get the current rotation count that the rotor has rotated so far. 
        int getRotateCount() const;

        /// @brief Return the name (identifier) of this rotor. 
        string getIdentifier() const;

        /// @brief Return the letter at the given index.
        /// @param index The index in the `LETTERS` array to search for.
        char getLetter(int index) const;

        /// @brief Return the current letter based on the current setting. This function calls the `getLetter()` function with `currentSetting - 1` passed into the parameter. 
        char getCurrentLetter() const;

        /// @brief Connect another, premade rotor object to this rotor so they are connected and can be manipulated when this rotor rotates.
        void connectRotor(Rotor* connectedRotor);

        /// @brief Shift the current setting one step up. If the current setting is at 26, the next will be 1 (looping back from Z to A). This function replicate the physical action of rotating the rotor.
        void rotate();

        /// @brief Encrypt the given character by converting the current setting into the ASCII value of the encrypted character
        char encryptCharacter(char c);

        void print();

        /// @brief Initialize the `wiring` member variable by randomly assigning every key-value pair.
        map<char, char> initWiring();

        /// @brief Generate a random integer from the given range without repeating numbers.
        static int randomIndex(int start, int end);
};

ostream& operator<<(Rotor& rotor, ostream& out);

#endif