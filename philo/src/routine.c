/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:43:25 by haitkadi          #+#    #+#             */
/*   Updated: 2022/05/11 18:43:27 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *args)
{
    t_thread  *thread;
    int       philo;
    
    thread = (t_thread *)args;
    if(thread->index % 2)
        usleep(100);
    while (thread->data->state)
    {
        take_fork(thread, thread->index);
        take_fork(thread->next, thread->index);
        eating(thread);

        put_fork(thread->next);
        put_fork(thread);

        sleeping(thread);
        thinking(thread);
    }
    return (NULL);
}
