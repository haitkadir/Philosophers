#include "../../src/philo.h"

long ft_current_time(void)
{
    struct timeval  start;

    gettimeofday(&start, NULL);
    return ((start.tv_sec * 1000000 + start.tv_usec) / 1000);

}