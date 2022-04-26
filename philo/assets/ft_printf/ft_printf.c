/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:04:36 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/02 16:04:40 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static	int	process_data(t_args args, va_list ap)
{
	int	len;

	len = 0;
	if (args.type == 'd' || args.type == 'i')
		len = process_d(va_arg(ap, int), args);
	else if (args.type == 'u')
		len = process_u(va_arg(ap, unsigned int), args);
	else if (ft_tolower(args.type) == 'x')
		len = process_x(va_arg(ap, unsigned int), args);
	else if (args.type == 'p')
		len = process_p(va_arg(ap, unsigned long), args);
	else if (args.type == 's')
		len = process_s(va_arg(ap, char *), args);
	else if (args.type == 'c')
		len = process_c(va_arg(ap, int), args);
	return (len);
}

static	int	formater(va_list ap, const char *frmt)
{
	int		i;
	int		len;
	t_args	args;

	i = 0;
	len = 0;
	while (frmt[i])
	{
		ft_bzero(&args.flags, sizeof(args.flags));
		ft_bzero(&args, sizeof(args));
		if (frmt[i] == '%' && frmt[i + 1] == '%')
			len += ft_putchar(frmt[++i]);
		else if (frmt[i] == '%' && frmt[i + 1] != '%')
		{
			i = manage_flags(frmt, i + 1, &args);
			len += process_data(args, ap);
		}
		else
			len += ft_putchar(frmt[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *frmt, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	while (frmt[i])
	{
		if (frmt[i] == '%' && frmt[i + 1] != '%')
		{
			if (check_error(&frmt[i + 1]))
				return (-1);
		}
		else if (frmt[i] == '%' && frmt[i + 1] == '%')
			i++;
		i++;
	}
	va_start(ap, frmt);
	len += formater(ap, frmt);
	va_end(ap);
	return (len);
}
