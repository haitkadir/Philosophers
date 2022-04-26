/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:00:51 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/08 23:01:00 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	count_hexa(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 16)
		len++;
	else if (n > 15)
	{
		len += count_hexa(n / 16);
		len += count_hexa(n % 16);
	}
	return (len);
}

static int	put_prefix(char c)
{
	int	len;

	len = 0;
	len += ft_putchar('0');
	len += ft_putchar(c);
	return (len);
}

static void	handler(t_args *args, unsigned int argument, char *rest)
{
	if (!(args->precision) && !(args->flags.minus) && (args->flags.ziro))
		*rest = '0';
	if (args->precision >= count_hexa(argument))
		args->precision -= count_hexa(argument);
	else
		args->precision = 0;
	if (args->width >= args->precision + count_hexa(argument))
		args->width -= (args->precision + count_hexa(argument));
	else
		args->width = 0;
}

int	process_x(unsigned int argument, t_args args)
{
	int		len;
	char	rest;

	len = 0;
	rest = ' ';
	handler(&args, argument, &rest);
	if (args.flags.minus)
	{
		if (args.flags.hash && argument)
			len += put_prefix(args.type);
		len += print_precicion(args.precision);
		len += ft_puthexa(argument, args.type);
		len += print_width(args.width, rest);
	}
	else
	{
		if (args.flags.hash && argument)
			len += put_prefix(args.type);
		len += print_width(args.width, rest);
		len += print_precicion(args.precision);
		len += ft_puthexa(argument, args.type);
	}
	return (len);
}
