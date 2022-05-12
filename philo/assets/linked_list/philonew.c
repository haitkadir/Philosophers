/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philonew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:46:38 by haitkadi          #+#    #+#             */
/*   Updated: 2022/05/12 14:46:44 by haitkadi         ###   ########.fr       */
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
	temp->index = i;
	temp->last_meal = ft_current_time();
	temp->data = data;
	temp->data->state = 1;
	temp->meals = 0;
	pthread_mutex_init(&temp->data->mutex, NULL);
	pthread_create(&temp->thread, NULL, &routine, (void *)temp);
	temp->next = temp;
	return (temp);
}
