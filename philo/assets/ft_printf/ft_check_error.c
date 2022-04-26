/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <haitkadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:44:27 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/13 17:15:32 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_compatible(t_args args)
{
	if (args.flags.ziro && !ft_strchr("diuxX", args.type))
		return (1);
	if (args.is_precision && !ft_strchr("sdiuxX", args.type))
		return (1);
	if (args.flags.hash && !ft_strchr("xX", args.type))
		return (1);
	if (args.flags.space && !ft_strchr("sdi", args.type))
		return (1);
	if (args.flags.plus && !ft_strchr("di", args.type))
		return (1);
	return (0);
}

static int	check_incompatible_flags(const char *frmt)
{
	t_args	args;
	int		i;

	ft_bzero(&args.flags, sizeof(args.flags));
	ft_bzero(&args, sizeof(args));
	i = 0;
	manage_flags(frmt, 0, &args);
	if (is_compatible(args))
		return (1);
	return (0);
}

int	check_error(const char *frmt)
{
	int	i;
	int	j;
	int	invalid_pre;

	i = 0;
	j = 0;
	invalid_pre = 0;
	while (ft_strchr(" -+#.0123456789", frmt[j]))
	{
		if (frmt[j] == '.')
			invalid_pre++;
		if ((frmt[j] == '.') && !ft_strchr("0123456789cspdiuxX", frmt[j + 1]))
			invalid_pre++;
		j++;
	}
	if (!ft_strchr("cspdiuxX", frmt[j]) || invalid_pre > 1)
		return (1);
	if (check_incompatible_flags(frmt))
		return (1);
	return (0);
}
