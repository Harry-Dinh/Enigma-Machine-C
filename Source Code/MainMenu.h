#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "Rotor.h"

using namespace std;

/// @brief A class that contains all of the functions to run the main interface of the program
class MainMenu {
    private:
        /// @brief The main rotor of the Enigma machine
        Rotor* mainRotor;

    public:
        /// @brief The user's choice for navigating the main menu
        int choice;

        /// @brief The user's string input for encryption/decryption
        string userInput;

        /// @brief The stored output after encrypting/decrypting that can be written into a text file
        string currentOutput;

        /// @brief A boolean indicating whether the program is running or not
        bool isRunning;

        /// @brief `MainMenu` constructor
        MainMenu();

        /// @brief `MainMenu` destructor
        ~MainMenu();

        /// @brief Run the main user interface for the Enigma++ program
        void runMenu();

        /// @brief Print the list of choices that the user can enter
        void printChoices();

        /// @brief Run option 1 of the program that encrypts the given message
        void encryptMessage();
};

#endif