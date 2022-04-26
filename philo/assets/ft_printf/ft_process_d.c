/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:00:51 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/07 23:01:00 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	handler(t_args *args, int argument, char *rest)
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
	if (args->width && (argument < 0 || args->flags.plus || args->flags.space))
		args->width--;
}

int	process_d(int argument, t_args args)
{
	int		len;
	char	rest;

	len = 0;
	rest = ' ';
	handler(&args, argument, &rest);
	if (args.flags.minus)
	{
		len += print_sign(args, argument);
		len += print_precicion(args.precision);
		len += ft_putnbr(argument);
		len += print_width(args.width, rest);
	}
	else
	{
		if (args.width && !args.flags.ziro)
			len += print_width(args.width, rest);
		len += print_sign(args, argument);
		if (args.width && args.flags.ziro)
			len += print_width(args.width, rest);
		len += print_precicion(args.precision);
		len += ft_putnbr(argument);
	}
	return (len);
}
