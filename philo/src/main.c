#include "philo.h"

// pthread_mutex_t mutex;




void *philosopher(void *args)
{
    t_data *data;
    data = (t_data *)args;
    printf("philosopher%d\n", data->philos_len);
    return (NULL);
}

static char recipe(t_data *data)
{

    pthread_t th[data->philos_len];
    int i;

    i = 0;
    while (i < data->philos_len)
    {
        if (pthread_create(&th[i], NULL, &philosopher, (void *)data))
            return (1);
        i++;
    }
    i = 0;
    {
        if (pthread_join(th[i], NULL))
            return (1);
        i++;
    }
    return (0);
}

int main()
{
    t_data *data;

    data = NULL;
    data = (t_data *)ft_calloc(1, sizeof(t_data));
    if (!data)
        return (-1);
    data->philos_len = 5;
    data->forks = data->philos_len;
    data->time_to_die = 5000;
    data->time_to_eat = 3;
    data->time_to_sleep = 10000;
    if (recipe(data))
        return(ft_putstr_fd("an error occurd", 2), -1);
    return (0);
}
