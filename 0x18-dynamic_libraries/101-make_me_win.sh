#include <stdio.h>
#include <stdlib.h>

/**
 * srand - Overwrites the srand function in the libc shared object
 * @seed: The seed to use for the random number generator. [Will be Ignored]
 */
void srand(unsigned int seed)
{
    fputs("9 8 10 24 75 - 9\nCongratulations, you win the Jackpot!\n", stdout);
    exit(EXIT_SUCCESS);
}
