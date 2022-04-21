/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:05:24 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/19 22:05:26 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>

#include "../assets/libft/libft.h"
/*---------------------------------- Data struct ---------------------------*/
typedef struct s_data
{
    int philos_len;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_meals;
}   t_data;
/*----------------------------- LInked list node -------------------------*/
typedef struct s_thread
{
	struct s_thread	*prev;
	pthread_t       thread;
    pthread_mutex_t fork;
    int             state;
    t_data          *data;
	struct s_thread	*next;
}	t_thread;
/*----------------------------- LInked list functions ------------------------*/
void        philoadd_back(t_thread **lst, t_thread *new);
void        philodelone(t_thread *lst);
t_thread	*philonew(t_data *data);
t_thread	*philolast(t_thread *lst);
t_thread	*philolast(t_thread *lst);
int         philosize(t_thread *lst);
/*---------------------------------- Algo functions ---------------------------*/
void    *routine(void *args);
char    create_threads(t_data *args);
char    recipe(t_data *data);

#endif
