#include "Rotor.h"

Rotor::Rotor(string identifier) {
    this->identifier = identifier;
    this->initialSetting = 1;
    this->currentSetting = 1;
    this->connectedRotor = nullptr;
}

Rotor::Rotor(string identifier, int initialSetting) {
    this->identifier = identifier;
    this->initialSetting = initialSetting;
    this->currentSetting = initialSetting;
    this->connectedRotor = nullptr;
}

Rotor::Rotor(string identifier, int initialSetting, Rotor* connectedRotor) {
    this->identifier = identifier;
    this->initialSetting = initialSetting;
    this->currentSetting = initialSetting;
    this->connectedRotor = connectedRotor;
}

Rotor::~Rotor() {
    delete connectedRotor;
}

int Rotor::getCurrentSetting() const { return this->currentSetting; }

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

void Rotor::rotate() {
    if (currentSetting == NUM_LETTERS) {
        currentSetting = 1;
        if (connectedRotor != nullptr) {
            /// @todo This might cause a recursive infinite loop...
            connectedRotor->rotate();
        }
    } else {
        currentSetting++;
    }
}