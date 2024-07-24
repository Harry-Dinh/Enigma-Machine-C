#include "MainMenu.h"

MainMenu::MainMenu() {
    this->mainRotor = new Rotor("Main rotor");
    this->choice = -1;
    this->userInput = "";
    this->isRunning = true;
    this->currentOutput = "";
}

MainMenu::~MainMenu() {
    delete mainRotor;
}

void MainMenu::runMenu() {
    while (isRunning) {
        // Printing the menu and getting the user's input
        cout << "ENIGMA++" << endl;
        printChoices();
        cin >> choice;

        // Validating the choice and run the appropriate function
        switch (choice) {
            case 1:
                cout << "Encrypt message option selected" << endl;
                encryptMessage();
                break;
            case 2:
                cout << "Decrypt message option seleced" << endl;
                break;
            case 3:
                cout << "Export message to file option selected" << endl;
                break;
            case 0:
                cout << "Stopping program..." << endl;
                isRunning = false;
                break;
            default:
                cout << "Not a choice on the list. 1-3 and 0 only!" << endl;
                continue;
        }
        cout << "\n" << endl;
    }
}

void MainMenu::printChoices() {
    cout << "Choices:" << endl;
    cout << "1. Encrypt message" << endl;
    cout << "2. Decrypt message" << endl;
    cout << "3. Export message to file" << endl;
    cout << "0. Stop program" << endl;
    cout << "Enter your choice (1-3 or 0): ";
}

void MainMenu::encryptMessage() {
    cout << "Enter your message (with no spaces): ";
    cin >> userInput;

    // Exit early if the user didn't enter anything
    if (userInput == "") {
        cout << "Message is empty, cannot encrypt!" << endl;
        return;
    }

    // Change every letter in the string to upper case
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
}