/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:00:51 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/07 23:01:00 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	process_c(char argument, t_args args)
{
	int	len;

	if (args.width)
		args.width--;
	len = 0;
	if (args.flags.minus)
	{
		len += ft_putchar(argument);
		len += print_width(args.width, ' ');
	}
	else
	{
		len += print_width(args.width, ' ');
		len += ft_putchar(argument);
	}
	return (len);
}
