#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>

typedef struct t_data
{
    int philos_len;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_meals
}   t_data;

#endif