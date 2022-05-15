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

void	print_state(t_data *data, int time, int index, char *state)
{
	if (data->state)
	{
		sem_wait(data->mutex_print);
		printf("\033[1;34m%6d ms| \033[1;32m%d \033[1;35m%s\033[0m\n", \
		time, index, state);
		sem_post(data->mutex_print);
	}
}

/*----------------------------------------------------------------------------*/

void	routine(t_data *data)
{
	if (data->index % 2)
		usleep(100);
	while (1)
	{
		take_fork(data);
		take_fork(data);
		eating(data);
		put_fork(data);
		put_fork(data);
		sleeping(data);
		thinking(data);
	}
	exit(0);
}

void	*child_routine(void *arg)
{
	t_data	*data;
	int		elapsed_time;

	data = (t_data *)arg;
	while (1)
	{
		elapsed_time = (int)ft_current_time() - data->last_meal;
		if (elapsed_time > data->time_to_die)
		{
			printf("\033[1;34m%6d ms| \033[1;32m%d \033[1;33mdied\033[0m\n", \
				(int)(ft_current_time() - data->start_time), data->index);
			exit(HAS_DIED);
		}
		else if (data->total_meals == data->meals)
			exit(HAS_EATEN);
		usleep(500);
	}
	return (NULL);
}
