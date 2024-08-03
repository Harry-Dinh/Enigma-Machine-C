#ifndef ENIGMA_TEST_H
#define ENIGMA_TEST_H

#include <iostream>
#include "Rotor.h"

using namespace std;

class EnigmaTest {
    protected:
        Rotor* testRotor;

    public:
        EnigmaTest();
        ~EnigmaTest();

        void testRotorEncryption();
        void testRotorRandomAssignment();
};

#endif