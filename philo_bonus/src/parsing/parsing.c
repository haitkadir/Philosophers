/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:23:49 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 18:23:52 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

static	void	free_allocation(char *tmp, char *tmp2, char *result)
{
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	if (result)
		free(result);
}

static void	join_args_util(char *arg, char **result)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strjoin(arg, " ");
	if (!tmp)
		return (free_allocation(tmp, tmp2, *result));
	tmp2 = *result;
	*result = NULL;
	if (tmp2)
		*result = ft_strjoin(tmp2, tmp);
	else
		*result = ft_strdup(tmp);
	if (!*result)
		return (free_allocation(tmp, tmp2, *result));
	free_allocation(tmp, tmp2, NULL);
}

static char	**join_args(int ac, char **av)
{
	int		i;
	char	*result;
	char	**args;

	result = NULL;
	i = 1;
	while (i < ac)
	{
		join_args_util(av[i], &result);
		i++;
	}
	if (!result)
		return (free_allocation(NULL, NULL, result), NULL);
	args = ft_split(result, ' ');
	return (free_allocation(NULL, NULL, result), args);
}

char	**parsing(int ac, char **av)
{
	char	**args;

	args = NULL;
	if (check_is_empty(ac, av))
		return (\
		ft_putstr_fd("\033[4;31mEmpty argument\033[0m\n", 2),
			NULL);
	args = join_args(ac, av);
	if (handle_input_errs(arr_len(args), args))
		return (free_2d_arr(args), NULL);
	return (args);
}
