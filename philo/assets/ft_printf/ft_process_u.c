/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:00:51 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/08 23:01:00 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handler(t_args *args, unsigned int argument, char *rest)
{
	if (!(args->precision) && !(args->flags.minus) && (args->flags.ziro))
		*rest = '0';
	if (args->precision >= ft_numlen(argument))
		args->precision -= ft_numlen(argument);
	else
		args->precision = 0;
	if (args->width >= args->precision + ft_numlen(argument))
		args->width -= (args->precision + ft_numlen(argument));
	else
		args->width = 0;
}

int	process_u(unsigned int argument, t_args args)
{
	int		len;
	char	rest;

	len = 0;
	rest = ' ';
	handler(&args, argument, &rest);
	if (args.flags.minus)
	{
		len += print_precicion(args.precision);
		len += ft_put_unsigned_nbr(argument);
		len += print_width(args.width, rest);
	}
	else
	{
		len += print_width(args.width, rest);
		len += print_precicion(args.precision);
		len += ft_put_unsigned_nbr(argument);
	}
	return (len);
}
