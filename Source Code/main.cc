#include <iostream>
#include "Rotor.h"

using namespace std;

int main() {
    // Rotor class test
    Rotor mainRotor = Rotor("Main", 1);
    Rotor* secondaryRotor = new Rotor("Secondary");
    mainRotor.connectRotor(secondaryRotor);

    return 0;
}