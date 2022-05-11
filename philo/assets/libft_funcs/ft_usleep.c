#include "../../src/philo.h"

void ft_usleep(unsigned long micros)
{
    unsigned long chunk;
    int max_usleep;

    max_usleep = 1000000 - 1;

    while (micros > 0)
    {
        if (micros > max_usleep)
            chunk = max_usleep;
        else
            chunk = micros;
        usleep(chunk);
        micros -= chunk;
    }
}