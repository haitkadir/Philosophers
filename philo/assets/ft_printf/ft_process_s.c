/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:00:51 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/07 23:01:00 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handler(t_args *args, char *argument, int *len_to_print)
{
	if (args->is_precision && args->precision >= (int)ft_strlen(argument))
		*len_to_print = ft_strlen(argument);
	else if (args->is_precision && args->precision < (int)ft_strlen(argument))
		*len_to_print = args->precision;
	if (args->width >= *len_to_print)
		args->width -= *len_to_print;
	else
		args->width = 0;
}

int	process_s(char *argument, t_args args)
{
	int	len;
	int	len_to_print;

	if (!argument)
		argument = "(null)";
	len = 0;
	len_to_print = ft_strlen(argument);
	handler(&args, argument, &len_to_print);
	if (args.flags.minus)
	{
		len += ft_putnstr(argument, len_to_print);
		len += print_width(args.width, ' ');
	}
	else
	{
		len += print_width(args.width, ' ');
		len += ft_putnstr(argument, len_to_print);
	}
	return (len);
}
