/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:07:08 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/04 19:07:12 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	char	check_negative(char **args, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (args[i][0] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	handle_input_errs(int len, char **args)
{
	if (!args)
		return (ft_putstr_fd("\033[4;31mAllocation faild\033[0m\n", 2), 1);
	if (check_is_number(len, args))
		return (\
		ft_putstr_fd("\033[4;31mNone integer value\033[0m\n", 2), 1);
	if (check_max_int(len, args))
		return (ft_putstr_fd("\033[4;31mInt overflow\033[0m\n", 2), 1);
	if (check_negative(args, len))
		return (ft_putstr_fd("\033[4;31mNegative number\033[0m\n", 2), 1);
	if (ft_atoi(args[0]) == 0)
		return (ft_putstr_fd("\033[4;31mAt least one philo\033[0m\n", 2), 1);
	if (len == 5 && ft_atoi(args[4]) == 0)
		return (ft_putstr_fd("\033[4;31mAt least one meal\033[0m\n", 2), 1);
	if (len < 4 || len > 5)
	{
		return (\
		ft_putstr_fd("\033[4;31mLess/more than expected args\033[0m\n", 2), 1);
	}
	return (0);
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}
