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

        switch (input) {
            case 0:
                cout << "Stopping program now..." << endl;
                isRunning = false;
                break;
            case 1:
                mainRotor.rotate();
                mainRotor.print();
                secondaryRotor->print();
            default:
                cout << "Not an option, 1 or 0 only!" << endl;
        }
    }

    return 0;
}