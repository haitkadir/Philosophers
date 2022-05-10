#include "philo.h"

void thinking(t_thread *thread)
{
    int time;

    time = (int)(ft_current_time() - thread->data->start_time);
    thread->state = Think;
    pthread_mutex_lock(&thread->data->mutex);
    printf("%d ms| %d is thinking\n", time, thread->index);
    pthread_mutex_unlock(&thread->data->mutex);
}

void eating(t_thread *thread)
{
    int time;

    time = (int)(ft_current_time() - thread->data->start_time);
    thread->state = Eat;
    pthread_mutex_lock(&thread->data->mutex);
    printf("%d ms| %d is eating\n", time, thread->index);
    pthread_mutex_unlock(&thread->data->mutex);
    thread->last_meal = ft_current_time();
    ft_usleep(thread->data->time_to_eat * 1000);
}

void sleeping(t_thread *thread)
{
    int time;

    time = (int)(ft_current_time() - thread->data->start_time);
    thread->state = Sleep;
    pthread_mutex_lock(&thread->data->mutex);
    printf("%d ms| %d is sleeping\n", time, thread->index);
    pthread_mutex_unlock(&thread->data->mutex);
    ft_usleep(thread->data->time_to_sleep * 1000);
}

void take_fork(t_thread *thread, int x)
{
    int time;

    pthread_mutex_lock(&thread->fork);
    time = (int)(ft_current_time() - thread->data->start_time);
    pthread_mutex_lock(&thread->data->mutex);
    printf("%d ms| %d has taken a fork\n", time, x);
    pthread_mutex_unlock(&thread->data->mutex);
}

void put_fork(t_thread *thread, int x)
{
    pthread_mutex_unlock(&thread->fork);
}