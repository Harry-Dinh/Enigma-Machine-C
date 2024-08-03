#include <iostream>
#include "Rotor.h"
#include "MainMenu.h"
#include "EnigmaTest.h"

using namespace std;

int main() {
    // Initialize the main menu for running the program
    // Comment out the next two lines if you need to write some test codes
    // MainMenu mainMenu = MainMenu();
    // mainMenu.runMenu();

    // Test rotor encryption functionality
    EnigmaTest test = EnigmaTest();
    test.testRotorRandomAssignment();

    return 0;
}