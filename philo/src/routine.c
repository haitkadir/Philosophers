#include "philo.h"

void    *routine(void *args)
{
    t_thread  *thread;
    int       philo;
    
    thread = (t_thread *)args;
    if(thread->index % 2)
        usleep(100);
    while (thread->state)
    {
        take_fork(thread, thread->index);
        take_fork(thread->next, thread->index);
        eating(thread);

        put_fork(thread->next, thread->index);
        put_fork(thread, thread->index);

        sleeping(thread);
        thinking(thread);
    }
    return (NULL);
}
