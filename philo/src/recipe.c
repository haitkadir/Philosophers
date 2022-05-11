/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:43:07 by haitkadi          #+#    #+#             */
/*   Updated: 2022/05/11 18:43:12 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
/*----------------------------------------------------------------------------*/
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
/*----------------------------------------------------------------------------*/
void check_philos(t_thread *thread)
{
    int time;

    while (1)
    {
        time = (int)(ft_current_time() - thread->data->start_time);
        if ((ft_current_time() - thread->last_meal) > thread->data->time_to_die)
        {
            thread->data->state = 0;
            thread->state = Died;
            printf("%d ms| %d died\n", time, thread->index);
            break;
        }
        if (thread->data->meals && thread->data->total_meals == thread->data->philos_len)
        {
            thread->data->state = 0;
            break ;
        }
        thread = thread->next;
        usleep(500);
    }
}
/*----------------------------------------------------------------------------*/
void free_data(t_thread *thread, t_data *data)
{
    int i;
    t_thread *tmp;

    i = 0;
    while (i < data->philos_len)
    {
        tmp = thread;
        free(tmp);
        thread = thread->next;
        i++;
    }
    free(data);
}
/*----------------------------------------------------------------------------*/
char recipe(t_data *data)
{
    t_thread    *thread;

    thread = NULL;
    thread = create_threads(data);
    if (thread == NULL)
        return (1);
    check_philos(thread);
    if (join_threads(thread))
        return (1);
    free_data(thread, data);

    return (0);
}
