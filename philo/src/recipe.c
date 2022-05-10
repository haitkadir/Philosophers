#include "philo.h"

t_thread    *create_threads(t_data *data)
{
    t_thread    *thread;
    t_thread    *temp;
    int         i;

    thread = NULL;
    i = 0;
    while (i < data->philos_len)
    {
        temp = NULL;
        temp = philonew(data, i+1);
        if (!temp)
            return (NULL);
        philoadd_back(&thread, temp);
        i++;
    }
    return (thread);
}

char    join_threads(t_thread *thread)
{
    t_thread *tail;

    tail = thread->prev;
    while (1)
    {
        pthread_detach(thread->thread);
        if (thread == tail)
            break ;
        thread = thread->next;
    }
    return (0);
}



char recipe(t_data *data)
{
    t_thread    *thread;
    int time;

    thread = NULL;
    thread = create_threads(data);
    if (thread == NULL)
        return (1);
    if (join_threads(thread))
        return (1);
    while (1)
    {
        time = (int)(ft_current_time() - thread->data->start_time);
        if ((ft_current_time() - thread->last_meal) >= thread->data->time_to_die)
        {
            thread->state = Died;
            printf("%d ms| %d died\n", time, thread->index);
            break;
        }
        thread = thread->next;
    }

    return (0);
} 28138