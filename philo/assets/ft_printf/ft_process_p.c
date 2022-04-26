/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:00:51 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/08 23:01:00 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_long_hexa(unsigned long n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n < 16)
		len += ft_putchar(base[n]);
	else if (n > 15)
	{
		len += ft_put_long_hexa(n / 16);
		len += ft_put_long_hexa(n % 16);
	}
	return (len);
}

static int	count_hexa(unsigned long n)
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

static void	handler(t_args *args, unsigned long argument)
{
	if (args->width >= count_hexa(argument) + 2)
		args->width -= count_hexa(argument) + 2;
	else
		args->width = 0;
}

int	process_p(unsigned long argument, t_args args)
{
	int	len;

	len = 0;
	handler(&args, argument);
	if (args.flags.minus)
	{
		len += put_prefix('x');
		len += ft_put_long_hexa(argument);
		len += print_width(args.width, ' ');
	}
	else
	{
		len += print_width(args.width, ' ');
		len += put_prefix('x');
		len += ft_put_long_hexa(argument);
	}
	return (len);
}
