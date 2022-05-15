/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:42:22 by haitkadi          #+#    #+#             */
/*   Updated: 2022/05/11 18:42:25 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	char	help(char *arg)
{
	if (!ft_strncmp(arg, "--help", 7) || !ft_strncmp(arg, "-h", 3))
	{
		printf("\033[1;34m _______________Usage________________ \033[0m\n");
		printf("\033[1;32m|>./philo_bonus\033[0;32m <arg1> ... <arg5> \
		|\033[0m\n");
		printf("\033[0;35m| Arg1: number of philosophers       |\033[0m\n");
		printf("\033[0;35m| Arg2: time to die                  |\033[0m\n");
		printf("\033[0;35m| Arg3: time to eat                  |\033[0m\n");
		printf("\033[0;35m| Arg4: time to sleep                |\033[0m\n");
		printf("\033[0;35m| Arg5: number of meals: Optional    |\033[0m\n");
		printf("\033[1;34m|____________________________________|\033[0m\n");
		return (0);
	}
	return (1);
}

static	void	fill_info(t_data *data, char **args)
{
	data->philos_len = ft_atoi(args[0]);
	data->time_to_die = ft_atoi(args[1]);
	data->time_to_eat = ft_atoi(args[2]);
	data->time_to_sleep = ft_atoi(args[3]);
	data->start_time = ft_current_time();
	data->total_meals = 0;
	data->meals = -1;
	if (arr_len(args) > 4)
		data->meals = ft_atoi(args[4]);
	data->state = 1;
	sem_unlink("mutex");
	data->mutex = sem_open("mutex", O_CREAT, 0644, data->philos_len);
	if (data->mutex == SEM_FAILED)
		exit(-1);
	sem_unlink("mutex_print");
	data->mutex_print = sem_open("mutex_print", O_CREAT, 0644, 1);
	if (data->mutex_print == SEM_FAILED)
		exit(-1);
	free_2d_arr(args);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**args;

	if (ac > 1)
	{
		if (ac == 2 && !help(av[1]))
			return (0);
		args = NULL;
		args = parsing(ac, av);
		if (!args)
			return (-1);
		ft_bzero(&data, sizeof(t_data));
		fill_info(&data, args);
		if (recipe(&data))
			return (ft_putstr_fd("\033[4;31mAn error occurd\033[0m\n", 2), -1);
	}
	else
		printf("Use --help for more information.\n");
	return (0);
}
