#include "CocktailPro.h"

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