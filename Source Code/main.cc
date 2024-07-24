#include <iostream>
#include "Rotor.h"
#include "MainMenu.h"

using namespace std;

int main() {
    // Initialize the main menu for running the program
    // Comment out the next two lines if you need to write some test codes
    MainMenu mainMenu = MainMenu();
    mainMenu.runMenu();
    return 0;
}