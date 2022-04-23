#include "philo.h"

static char help(char *arg)
{
    if (!ft_strncmp(arg, "--help", 7) || !ft_strncmp(arg, "-h", 3))
    {
        ft_putstr_fd("\033[1;34m _______________Usage________________ \033[0m\n", 1);
        ft_putstr_fd("\033[1;32m|>./philo\033[0;32m <arg1> ... <arg5>  \
        |\033[0m\n", 1);
        ft_putstr_fd("\033[0;35m| Arg1: number of philosophers       |\033[0m\n", 1);
        ft_putstr_fd("\033[0;35m| Arg2: time to die                  |\033[0m\n", 1);
        ft_putstr_fd("\033[0;35m| Arg3: time to eat                  |\033[0m\n", 1);
        ft_putstr_fd("\033[0;35m| Arg4: time to sleep                |\033[0m\n", 1);
        ft_putstr_fd("\033[0;35m| Arg5: number of meals: Optional    |\033[0m\n", 1);
        ft_putstr_fd("\033[1;34m|____________________________________|\033[0m\n", 1);
        return (0);
    }
    return (1);
}

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

static void fill_info(t_data *data, char **args)
{
    data->philos_len = ft_atoi(args[0]);
    data->time_to_die = ft_atoi(args[1]);
    data->time_to_eat = ft_atoi(args[2]);
    data->time_to_sleep = ft_atoi(args[3]);
    if (arr_len(args) > 4)
        data->number_of_meals = ft_atoi(args[4]);
    free_2d_arr(args);
}

int main(int ac, char **av)
{
    t_data *data;
    char    **args;

    if (ac > 1)
    {
            if (ac == 2 && !help(av[1]))
                return (0);
        args = NULL;
        args = parsing(ac, av);
        if (!args)
            return (-1);
        int i = 0;
        while (args[i])
            printf("%d\n", ft_atoi(args[i++]));
        data = NULL;
        data = (t_data *)ft_calloc(1, sizeof(t_data));
        if (!data)
            return (-1);
        fill_info(data, args);
        if (recipe(data))
            return(ft_putstr_fd("an error occurd", 2), -1);
    }
    return (0);
}
