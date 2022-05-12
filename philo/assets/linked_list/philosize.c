/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:47:02 by haitkadi          #+#    #+#             */
/*   Updated: 2022/05/12 14:47:11 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/philo.h"

int	philosize(t_thread *lst)
{
	int			i;
	t_thread	*tmp;

	if (!lst)
		return (0);
	i = 1;
	tmp = lst;
	while (lst->next != tmp)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
