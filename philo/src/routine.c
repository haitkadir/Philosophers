#include "philo.h"

void    *routine(void *args)
{
    t_thread  *thread;
    int       philo;
    
    thread = (t_thread *)args;
    while (1)
    {
        pthread_mutex_lock(&thread->data->mutex);
        ft_printf("philo:%d thinking ...\n", thread->index);
        // thread->state = 1;
        pthread_mutex_lock(&thread->fork);
        ft_printf("philo:%d has taken a fork\n", thread->index);
        pthread_mutex_lock(&thread->next->fork);
        ft_printf("philo:%d has taken a fork\n", thread->index);
        ft_printf("philo:%d Start eating ...\n", thread->index);
        // thread->state = 2;
        ft_usleep(thread->data->time_to_eat);
        pthread_mutex_unlock(&thread->fork);
        pthread_mutex_unlock(&thread->next->fork);

        ft_printf("philo:%d sleeping ...\n", thread->index);
        // thread->state = 3;
        ft_usleep(thread->data->time_to_sleep);
        thread = thread->next;
        pthread_mutex_unlock(&thread->data->mutex);
    }
    return (NULL);
}
