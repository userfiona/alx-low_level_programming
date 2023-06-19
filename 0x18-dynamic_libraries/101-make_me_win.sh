#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void srand(unsigned int seed)
{
    const char *nums_txt = "9 8 10 24 75 - 9\n";
    const char *txt = "Congratulations, you win the Jackpot!\n";

    (void)seed;
    fwrite(nums_txt, sizeof(char), 17, stdout);
    fwrite(txt, sizeof(char), 38, stdout);
    _exit(EXIT_SUCCESS);
}
