#include "Rotor.h"

Rotor::Rotor(string identifier) {
    cout << "Rotor constructor called" << endl;
    this->identifier = identifier;
    this->initialSetting = 1;
    this->currentSetting = 1;
    this->connectedRotor = nullptr;
    this->rotateCount = 0;
}

Rotor::Rotor(string identifier, int initialSetting) {
    cout << "Rotor constructor called" << endl;
    this->identifier = identifier;
    this->initialSetting = initialSetting;
    this->currentSetting = initialSetting;
    this->connectedRotor = nullptr;
    this->rotateCount = 0;
}

Rotor::Rotor(string identifier, int initialSetting, Rotor* connectedRotor) {
    cout << "Rotor constructor called" << endl;
    this->identifier = identifier;
    this->initialSetting = initialSetting;
    this->currentSetting = initialSetting;
    this->connectedRotor = connectedRotor;
    this->rotateCount = 0;
}

Rotor::~Rotor() {
    cout << "Rotor destructor called" << endl;
    delete connectedRotor;
}

int Rotor::getCurrentSetting() const { return this->currentSetting; }

int Rotor::getRotateCount() const { return this->rotateCount; }

string Rotor::getIdentifier() const { return this->identifier; }

string Rotor::getLetter(int index) const {
    if (index < 0 || index > NUM_LETTERS) {
        cout << "Rotor::getLetter()--Index out of bounds error!" << endl;
        /// @todo Try throwing an error here instead of crashing the program, and figure out how to handle it should it occur. Look up on how to throw and handle errors with C++.
        exit(1);
    }
    return letters[index];
}

void Rotor::connectRotor(Rotor* connectedRotor) { this->connectedRotor = connectedRotor; }

/// @todo Need to revise this function to accommodate the rotateCount variable!
void Rotor::rotate() {
    // This if statement set the current setting from 26 back to 1 so it doesn't continue counting from 27 onward
    if (currentSetting == NUM_LETTERS) {
        // Make sure that there is a connected rotor and the number of rotations must be 26 times to make the connected rotor rotate
        if (connectedRotor != nullptr && rotateCount == NUM_LETTERS) {
            /// @todo This might cause a recursive infinite loop...
            cout << connectedRotor->identifier <<  " has rotated" << endl;
            connectedRotor->rotate();
        }
        currentSetting = 1;
        rotateCount = 0;
    } else {
        // Continue counting the number of rotations and increment the setting to the next letter
        currentSetting++;
        rotateCount++;
    }
}

void Rotor::print() {
    cout << "=========================================" << endl;
    cout << "Name: " << this->identifier << endl;
    cout << "Current setting: " << this->currentSetting << endl;
    cout << "Rotate count: " << this->rotateCount << endl;
    cout << "=========================================\n" << endl;
}