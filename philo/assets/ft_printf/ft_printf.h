/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:04:50 by haitkadi          #+#    #+#             */
/*   Updated: 2021/12/02 16:04:57 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h> 

typedef struct t_flags
{
	int	minus;
	int	plus;
	int	hash;
	int	ziro;
	int	space;
}	t_flags;

typedef struct t_args
{
	int		width;
	int		precision;
	int		is_precision;
	char	type;
	t_flags	flags;
}	t_args;

int		ft_numlen(long n);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_tolower(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

int		check_error(const char *frmt);
int		manage_flags(const char *frmt, int i, t_args *args);

int		print_sign(t_args args, int argument);
int		print_precicion(int i);
int		print_width(int i, char c);

int		ft_putchar(char c);
int		ft_putnstr(char *s, int len_to_print);
int		ft_put_unsigned_nbr(unsigned int nb);
int		ft_putnbr(int n);
int		ft_puthexa(unsigned int n, char c);

int		process_d(int argument, t_args args);
int		process_u(unsigned int argument, t_args args);
int		process_x(unsigned int argument, t_args args);
int		process_p(unsigned long argument, t_args args);
int		process_s(char *argument, t_args args);
int		process_c(char argument, t_args args);

int		ft_printf(const char *frmt, ...);

#endif
