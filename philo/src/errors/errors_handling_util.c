/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:23:37 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/06 14:23:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_is_empty(int ac, char **av)
{
	int	i;
	int	j;
	int	res;

	i = 1;
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			return (1);
		else
		{
			j = 0;
			res = 0;
			while (av[i][j])
				if (av[i][j++] != ' ')
					res++;
			if (!res)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_max_int(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_is_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && !ft_strchr("-+", av[i][j]))
				return (1);
			else
			{
				if (ft_strlen(av[i]) > 1)
					j++;
				while (av[i][j] && ft_isdigit(av[i][j]))
					j++;
				if (av[i][j] != 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}
