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
	pid_t		*philos;

	philos = 0;
	philos = (pid_t *)ft_calloc(data->philos_len, sizeof(pid_t));
	if (!philos)
		return (1);
	system("leaks philo_bonus");
	i = 0;
	while (i < data->philos_len)
	{
		philos[i] = fork();
		if (philos[i] == -1)
			return (free(philos), 1);
		else if (philos[i] == 0)
		{
			data->index = i + 1;
			data->last_meal = ft_current_time();
			pthread_create(&data->thread, NULL, &child_routine, (void *)data);
			pthread_detach(data->thread);
			routine(data);
			break ;
		}
		i++;
	}
	if (philos)
		free(philos);
	return (0);
}

/*----------------------------------------------------------------------------*/

static	void	destroy_data(t_data *data)
{
	sem_close(data->mutex);
	sem_close(data->mutex_print);
}

/*----------------------------------------------------------------------------*/

char	recipe(t_data *data)
{
	int	status;
	int	philos_has_eaten;
	int	has_died_flag;

	has_died_flag = 0;
	if (create_processes(data))
		return (ft_putstr_fd("ERROR\n", 2), 1);
	philos_has_eaten = 0;
	while (has_died_flag == 0 && philos_has_eaten != data->philos_len)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == HAS_DIED)
			has_died_flag = 1;
		else if (WEXITSTATUS(status) == HAS_EATEN)
			++philos_has_eaten;
		usleep(500);
	}
	write(1, "\033[30m", 5);
	destroy_data(data);
	if (has_died_flag)
		kill(0, SIGKILL);
	return (0);
}
