/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:37:16 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/12 18:37:25 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	flags_checker(char c, t_args **args)
{
	if (c == '-')
		(*args)->flags.minus = 1;
	else if (c == '+')
		(*args)->flags.plus = 1;
	else if (c == '#')
		(*args)->flags.hash = 1;
	else if (c == '0')
		(*args)->flags.ziro = 1;
	else if (c == ' ')
		(*args)->flags.space = 1;
}

int	manage_flags(const char *frmt, int i, t_args *args)
{
	while (ft_strchr("-+ 0#", frmt[i]))
		flags_checker(frmt[i++], &args);
	if (ft_isdigit(frmt[i]))
		args->width = ft_atoi(&frmt[i]);
	while (ft_isdigit(frmt[i]))
		i++;
	if (frmt[i] == '.')
	{
		args->is_precision = 1;
		args->precision = ft_atoi(&frmt[++i]);
	}
	while (ft_isdigit(frmt[i]))
		i++;
	if (ft_strchr("cspdiuxX", frmt[i]))
		args->type = frmt[i];
	return (i);
}
