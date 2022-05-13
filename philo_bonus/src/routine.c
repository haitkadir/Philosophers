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

void	print_state(t_thread *thread, int time, int index, char *state)
{
	if (thread->data->state)
	{
		pthread_mutex_lock(&thread->data->mutex);
		printf("\033[1;34m%d ms| \033[1;32m%d \033[1;35m%s\033[0m\n", \
		time, index, state);
		pthread_mutex_unlock(&thread->data->mutex);
	}
}

/*----------------------------------------------------------------------------*/

void	*routine(void *args)
{
	t_thread	*thread;

	thread = (t_thread *)args;
	if (thread->index % 2)
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
