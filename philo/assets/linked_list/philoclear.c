/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:48:58 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/15 16:49:02 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../src/philo.h"

void	philoclear(t_thread **lst)
{
	t_thread	*head;
	t_thread	*tmp;

	if (!*lst)
		return ;
	head = *lst;
	*lst = NULL;
	while (head->next != *lst)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
