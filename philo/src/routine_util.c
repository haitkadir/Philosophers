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

void	thinking(t_thread *thread)
{
	int	time;

	time = (int)(ft_current_time() - thread->data->start_time);
	print_state(thread, time, thread->index, "is thinkin");
}

/*----------------------------------------------------------------------------*/

void	eating(t_thread *thread)
{
	int	time;

	time = (int)(ft_current_time() - thread->data->start_time);
	thread->last_meal = ft_current_time();
	print_state(thread, time, thread->index, "is eating");
	thread->meals++;
	if (thread->meals == thread->data->meals)
		thread->data->total_meals++;
	ft_usleep(thread->data->time_to_eat * 1000);
}

/*----------------------------------------------------------------------------*/

void	sleeping(t_thread *thread)
{
	int	time;

	time = (int)(ft_current_time() - thread->data->start_time);
	print_state(thread, time, thread->index, "is sleeping");
	ft_usleep(thread->data->time_to_sleep * 1000);
}

/*----------------------------------------------------------------------------*/

void	take_fork(t_thread *thread, int index)
{
	int	time;

	pthread_mutex_lock(&thread->fork);
	time = (int)(ft_current_time() - thread->data->start_time);
	print_state(thread, time, index, "has taken a fork");
}

/*----------------------------------------------------------------------------*/

void	put_fork(t_thread *thread)
{
	pthread_mutex_unlock(&thread->fork);
}
