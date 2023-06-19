#include <stdio.h>

void srand(unsigned int seed)
{
    const char nums_txt[] = "9 8 10 24 75 - 9\n";
    const char txt[] = "Congratulations, you win the Jackpot!\n";

    (void)seed;
    fputs(nums_txt, stdout);
    fputs(txt, stdout);
}
