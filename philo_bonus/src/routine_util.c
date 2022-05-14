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

void	thinking(t_data *data)
{
	int	time;

	time = (int)(ft_current_time() - data->start_time);
	print_state(data, time, data->index, "is thinkin");
}

/*----------------------------------------------------------------------------*/

void	eating(t_data *data)
{
	int	time;

	data->last_meal = ft_current_time();
	time = (int)(ft_current_time() - data->start_time);
	print_state(data, time, data->index, "is eating");
	ft_usleep(data->time_to_eat * 1000);
	data->meals++;
	if (data->meals == data->meals)
		data->total_meals++;
}

/*----------------------------------------------------------------------------*/

void	sleeping(t_data *data)
{
	int	time;

	time = (int)(ft_current_time() - data->start_time);
	print_state(data, time, data->index, "is sleeping");
	ft_usleep(data->time_to_sleep * 1000);
}

/*----------------------------------------------------------------------------*/

void	take_fork(t_data *data)
{
	int	time;

	sem_wait(data->mutex);
	time = (int)(ft_current_time() - data->start_time);
	print_state(data, time, data->index, "has taken a fork");
}

/*----------------------------------------------------------------------------*/

void	put_fork(t_data *data)
{
	sem_post(data->mutex);
}
