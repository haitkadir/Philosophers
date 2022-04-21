/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:22:37 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/14 22:22:41 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../src/philo.h"

int	philosize(t_thread *lst)
{
	int	i;
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
