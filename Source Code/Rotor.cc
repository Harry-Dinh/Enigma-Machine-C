#include "Rotor.h"

Rotor::Rotor() {
    this->identifier = "Unnamed rotor";
    this->initialSetting = 1;
    this->currentSetting = 1;
    this->connectedRotor = nullptr;
    this->rotationCount = 0;
}

Rotor::Rotor(string identifier) {
    this->identifier = identifier;
    this->initialSetting = 1;
    this->currentSetting = 1;
    this->connectedRotor = nullptr;
    this->rotationCount = 0;
    this->wiring = initWiring();
}

Rotor::Rotor(string identifier, int initialSetting) {
    this->identifier = identifier;
    this->initialSetting = initialSetting;
    this->currentSetting = initialSetting;
    this->connectedRotor = nullptr;
    this->rotationCount = 0;
    this->wiring = initWiring();
}

Rotor::Rotor(string identifier, int initialSetting, Rotor* connectedRotor) {
    this->identifier = identifier;
    this->initialSetting = initialSetting;
    this->currentSetting = initialSetting;
    this->connectedRotor = connectedRotor;
    this->rotationCount = 0;
    this->wiring = initWiring();
}

Rotor::~Rotor() {
    delete connectedRotor;
}

int Rotor::getCurrentSetting() const { return this->currentSetting; }

int Rotor::getRotateCount() const { return this->rotationCount; }

string Rotor::getIdentifier() const { return this->identifier; }

char Rotor::getLetter(int index) const {
    if (index < 0 || index > NUM_LETTERS) {
        cout << "Rotor::getLetter()--Index out of bounds error!" << endl;
        /// @todo Try throwing an error here instead of crashing the program, and figure out how to handle it should it occur. Look up on how to throw and handle errors with C++.
        exit(1);
    }
    return LETTERS[index];
}

char Rotor::getCurrentLetter() const { return getLetter(currentSetting - 1); }

void Rotor::connectRotor(Rotor* connectedRotor) { this->connectedRotor = connectedRotor; }

void Rotor::rotate() {
    // Increase the current setting or reset it
    if (currentSetting < NUM_LETTERS) {
        currentSetting++;
    } else {
        currentSetting = 1;
    }

    // Update the rotation (and connected rotor if available)
    if (rotationCount < NUM_LETTERS) {
        rotationCount++;
    } else {
        // Check if there is a connected rotor (if there is, rotate it)
        if (connectedRotor != nullptr) {
            connectedRotor->rotate();
        }

        // Reset the rotation count back to zero
        rotationCount = 0;
    }
}

char Rotor::encryptCharacter(char c) {
    
}

void Rotor::print() {
    cout << "=========================================" << endl;
    cout << "Name: " << this->identifier << endl;
    cout << "Current setting: " << this->currentSetting << endl;
    cout << "Rotate count: " << this->rotationCount << endl;
    cout << "=========================================\n" << endl;
}

map<char, char> Rotor::initWiring() {
    map<char, char> wiring;
    int inputIndex = 0;
    char inValue;
    char outValue;

    for (int outputIndex = 0; outputIndex < NUM_LETTERS; ++outputIndex) {
        inValue = LETTERS[randomIndex(0, NUM_LETTERS - 1)];
        outValue = LETTERS[outputIndex];
        wiring[inValue] = outValue;
    }
    return wiring;
}

int Rotor::randomIndex(int start, int end) {
    /// @note This is not generating unique numbers, need to find a different way to generate random unique numbers!
    return rand() % (end - start + 1) + start;
}

ostream& operator<<(Rotor& rotor, ostream& out) {
    out << "=========================================" << endl;
    out << "Name: " << rotor.getIdentifier() << endl;
    out << "Current setting: " << rotor.getCurrentSetting() << endl;
    out << "Rotate count: " << rotor.getRotateCount() << endl;
    out << "=========================================\n" << endl;
    return out;
}