/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:09:52 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 18:09:56 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/philo.h"

static	int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

long	ft_atol(const char *str)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - 48);
		if (result < INT_MIN || result > INT_MAX)
			return (2147483649);
	}
	return (result * sign);
}
