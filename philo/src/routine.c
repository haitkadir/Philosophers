#include "philo.h"

void    *routine(void *args)
{
    t_thread  *thread;
    
    thread = (t_thread *)args;
    while (1)
    {
        pthread_mutex_lock(&thread->prev->fork);
        printf("philo:%d Start eating\n", thread->index);
        usleep(200000);
        usleep(thread->data->time_to_eat);
        pthread_mutex_unlock(&thread->fork);
        thread = thread->next;
    }
    return (NULL);
}
