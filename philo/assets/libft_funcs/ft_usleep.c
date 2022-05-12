/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:49:08 by haitkadi          #+#    #+#             */
/*   Updated: 2022/05/12 14:49:11 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/philo.h"

void	ft_usleep(unsigned long micros)
{
	unsigned long	start_time;
	unsigned long	current_time;

	start_time = ft_current_time();
	while (1)
	{
		current_time = (ft_current_time() - start_time) * 1000;
		if (current_time >= micros)
			break ;
		usleep(10);
	}
}
