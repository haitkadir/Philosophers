#include "philo.h"

void    *routine(void *args)
{
    t_thread  *thread;
    
    thread = (t_thread *)args;
    while (1)
    {
        pthread_mutex_lock(&thread->fork);
        printf("Start eating: %p\n", thread);
        usleep(thread->data->time_to_eat);
        pthread_mutex_unlock(&thread->fork);
    }
    return (NULL);
}