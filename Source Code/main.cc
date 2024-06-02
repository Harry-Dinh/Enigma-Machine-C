#include <iostream>
#include "Rotor.h"

using namespace std;

int main() {
    bool isRunning = true;
    int input;

    // Rotor class test
    Rotor mainRotor = Rotor("Main", 1);
    Rotor* secondaryRotor = new Rotor("Secondary");
    mainRotor.connectRotor(secondaryRotor);

    while(isRunning) {
        cout << "Enter 1 to test, 0 to stop: ";
        cin >> input;

        if (input == 1) {
            mainRotor.rotate();
            mainRotor.print();
            secondaryRotor->print();
        } else {
            cout << "Stopping test" << endl;
            isRunning = false;
        }
    }

    return 0;
}