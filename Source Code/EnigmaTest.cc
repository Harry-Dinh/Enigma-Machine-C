#include "EnigmaTest.h"

EnigmaTest::EnigmaTest() {
    this->testRotor = new Rotor();
}

EnigmaTest::~EnigmaTest() {
    delete testRotor;
}

void EnigmaTest::testRotorEncryption() {

}

void EnigmaTest::testRotorRandomAssignment() {
    for (int i = 0; i < NUM_LETTERS; ++i) {
        cout << Rotor::randomIndex(0, NUM_LETTERS - 1) << endl;
    }
}