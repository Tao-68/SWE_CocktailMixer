// Main.cpp
// Ralf Hahn,  06.09.2019

#include "CocktailPro.h"
#include <iostream>

/**
 * @brief Generate a CocktailPro and start it
 * @param argc
 * @param argv
 * @return The standard system integer.
 */
int main(int argc, char * argv[]) {
    CocktailPro cp(argc, argv);
    cp.start();
    return 0;
}

/** Aenderung nur im Testbranch
* Zeile mit provoziertem Konflikt von Test_branch aus
*/