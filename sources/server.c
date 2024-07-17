#include "../include/minitalk.h"

void bit_handler(int SIG)
{
    static int binary = 0;
    static char bit = 8;
    // binary = binary * 2 + bit;
    bit--;
    if(SIG == SIGUSR2)
        binary |= (1 << bit);
    if (bit == 0)
    {
        write(1, &binary, 1);
        if (binary == 0)
            write(1, "\n", 1);
        bit = 8;
        binary = 0;
    }
}

int main ()
{
    ft_printf("PID : < %d >\n", getpid());
    signal(SIGUSR1, bit_handler);
    signal(SIGUSR2, bit_handler);
    while (1)
        pause();
    return (0);
}