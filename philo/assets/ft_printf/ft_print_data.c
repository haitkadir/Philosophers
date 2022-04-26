/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:05:07 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/02 16:05:10 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnstr(char *s, int len_to_print)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && len_to_print--)
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		len += 10;
	}
	else if (nb >= 0 && nb <= 9)
		len += ft_putchar(nb + '0');
	else if (nb > 9 && nb <= 2147483647)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else if (nb < 0 && nb >= -2147483648)
		len += ft_putnbr(nb * -1);
	return (len);
}

int	ft_puthexa(unsigned int n, char c)
{
	char	*base;
	int		len;

	len = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'x')
		base = "0123456789abcdef";
	if (n >= 0 && n < 16)
		len += ft_putchar(base[n]);
	else if (n > 15)
	{
		len += ft_puthexa(n / 16, c);
		len += ft_puthexa(n % 16, c);
	}
	return (len);
}

int	ft_put_unsigned_nbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb <= 9)
		len += ft_putchar(nb + '0');
	else if (nb > 9)
	{
		len += ft_put_unsigned_nbr(nb / 10);
		len += ft_put_unsigned_nbr(nb % 10);
	}
	return (len);
}
