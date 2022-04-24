/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:33:05 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/30 20:11:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../src/philo.h"

t_thread	*philonew(t_data *data, int i)
{
	t_thread		*temp;

	temp = (t_thread *)malloc(sizeof(t_thread));
	if (!temp)
		return (NULL);
	temp->prev = temp;
	pthread_mutex_init(&temp->fork, NULL);
	temp->state = 1;
	temp->index = i;
	temp->data = data;
	pthread_create(&temp->thread, NULL, &routine, (void *)temp);
	temp->next = temp;
	return (temp);
}
