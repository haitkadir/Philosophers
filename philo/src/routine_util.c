/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:43:37 by haitkadi          #+#    #+#             */
/*   Updated: 2022/05/11 18:43:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_state(t_thread *thread, int time, int index, char *state)
{
    if (thread->data->state)
    {
        pthread_mutex_lock(&thread->data->mutex);
        printf("%d ms| %d %s\n", time, index, state);
        pthread_mutex_unlock(&thread->data->mutex);
    }
}
/*----------------------------------------------------------------------------*/
void thinking(t_thread *thread)
{
    int time;

    time = (int)(ft_current_time() - thread->data->start_time);
    thread->state = Think;
    print_state(thread, time, thread->index, "is thinkin");
}
/*----------------------------------------------------------------------------*/
void eating(t_thread *thread)
{
    int time;

    thread->state = Eat;
    time = (int)(ft_current_time() - thread->data->start_time);
    thread->last_meal = ft_current_time();
    print_state(thread, time, thread->index, "is eating");
    ft_usleep(thread->data->time_to_eat * 1000);
    thread->meals++;
    if (thread->meals == thread->data->meals)
        thread->data->total_meals++;
}
/*----------------------------------------------------------------------------*/
void sleeping(t_thread *thread)
{
    int time;

    time = (int)(ft_current_time() - thread->data->start_time);
    thread->state = Sleep;
    print_state(thread, time, thread->index, "is sleeping");
    ft_usleep(thread->data->time_to_sleep * 1000);
}
/*----------------------------------------------------------------------------*/
void take_fork(t_thread *thread, int index)
{
    int time;

    pthread_mutex_lock(&thread->fork);
    time = (int)(ft_current_time() - thread->data->start_time);
    print_state(thread, time, index, "has taken a fork");
}
/*----------------------------------------------------------------------------*/
void put_fork(t_thread *thread)
{
    pthread_mutex_unlock(&thread->fork);
}
