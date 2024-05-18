#include "Rotor.h"

Rotor::Rotor(string identifier) {
    this->identifier = identifier;
    this->initialSetting = 1;
    this->currentSetting = 1;
}

Rotor::Rotor(string identifier, int initialSetting) {
    this->identifier = identifier;
    this->initialSetting = initialSetting;
    this->currentSetting = initialSetting;
}

int Rotor::getCurrentSetting() const { return this->currentSetting; }

string Rotor::getIdentifier() const { return this->identifier; }

string Rotor::getLetter(int index) const {
    if (index < 0 || index > MAX_LETTERS) {
        cout << "Rotor::getLetter()--Index out of bounds error!" << endl;
        /// @todo Might want to do something else instead of crashing the program here...
        exit(1);
    }
    return letters[index];
}

void Rotor::rotate() {
    if (currentSetting == MAX_LETTERS) {
        currentSetting = 1;
    } else {
        currentSetting++;
    }

    /// @todo Might want to consider a condition where you direct the instruction to rotate the connected rotor after 26 rotations of the current one.
}