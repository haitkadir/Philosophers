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

char	create_processes(t_data *data)
{
	int			i;

	data->philos = (pid_t *)ft_calloc(data->philos_len, sizeof(pid_t));
	i = 0;
	sem_unlink("mutex");
	data->mutex = sem_open("mutex", O_CREAT, 0644, data->philos_len);
	if (data->mutex == SEM_FAILED)
		return (1);
	sem_unlink("mutex_print");
	data->mutex_print = sem_open("mutex_print", O_CREAT, 0644, 1);
	if (data->mutex_print == SEM_FAILED)
		return (1);
	while (i < data->philos_len)
	{
		data->philos[i] = fork();
		if (data->philos[i] == -1)
			return (1);
		else if (data->philos[i] == 0)
		{
			data->index = i + 1;
			routine(data);
			break ;
		}
		i++;
	}
	while (1)
		;
	return (0);
}

/*----------------------------------------------------------------------------*/

// char	join_threads(t_thread *thread)
// {
// 	t_thread	*tail;

// 	tail = thread->prev;
// 	while (1)
// 	{
// 		pthread_detach(thread->thread);
// 		if (thread == tail)
// 			break ;
// 		thread = thread->next;
// 	}
// 	return (0);
// }

/*----------------------------------------------------------------------------*/

// void	check_philos(t_thread *thread)
// {
// 	int	time;

// 	while (1)
// 	{
// 		time = (int)(ft_current_time() - thread->data->start_time);
// 		if ((ft_current_time() - thread->last_meal) > thread->data->time_to_die)
// 		{
// 			thread->data->state = 0;
// 			printf("%d ms| %d died\n", time, thread->index);
// 			break ;
// 		}
// 		if (thread->data->total_meals == thread->data->philos_len)
// 		{
// 			thread->data->state = 0;
// 			break ;
// 		}
// 		thread = thread->next;
// 		usleep(500);
// 	}
// }

/*----------------------------------------------------------------------------*/

// void	free_data(t_thread *thread, t_data *data)
// {
// 	int			i;
// 	t_thread	*tmp;

// 	i = 0;
// 	while (i < data->philos_len)
// 	{
// 		tmp = thread;
// 		pthread_mutex_destroy(&tmp->fork);
// 		free(tmp);
// 		thread = thread->next;
// 		i++;
// 	}
// 	pthread_mutex_destroy(&data->mutex);
// 	free(data);
// }

/*----------------------------------------------------------------------------*/

char	recipe(t_data *data)
{
	// int i;

	if (create_processes(data))
		{
			printf("ERROR\n");
			return (1);
		}
	// i = 0;
	// while (i < data->philos_len)
	// {
	// 	if (data->philos[i] == 0)
	// 	{
	// 		data->index = i + 1;
	// 		routine(data);
	// 		break ;
	// 	}
	// 	i++;
	// }
	return (0);
}
