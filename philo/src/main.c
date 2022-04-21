#include "philo.h"


char    create_threads(t_data *data)
{
    t_thread    *thread;
    t_thread    *temp;
    int         i;

    thread = NULL;
    i = 0;
    while (i < data->philos_len)
    {
        temp = NULL;
        temp = philonew(data);
        if (!temp)
            return (1);
        philoadd_back(&thread, temp);
        i++;
    }
    return (0);
}

char recipe(t_data *data)
{
    if (create_threads(data))
        return (1);
    
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
    data->time_to_die = 50000;
    data->time_to_eat = 10000;
    data->time_to_sleep = 10000;
    if (recipe(data))
        return(ft_putstr_fd("an error occurd", 2), -1);
    return (0);
}
