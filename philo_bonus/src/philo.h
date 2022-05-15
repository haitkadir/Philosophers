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
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <time.h>
# include <sys/time.h>
# include <signal.h>
# include <stdio.h>

/*------------------------------------- Enums ------------------------------*/

typedef enum e_exit_status {
	HAS_DIED = 1,
	HAS_EATEN = 2,
}	t_exit_status;

/*---------------------------------- Data struct ---------------------------*/

typedef struct s_data
{
	int				philos_len;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	char			state;
	// pid_t			*philos;
	int				total_meals;
	long			last_meal;
	long			start_time;
	int				index;
	sem_t			*mutex;
	sem_t			*mutex_print;
	pthread_t		thread;
}	t_data;

/*----------------------------------- Utils ------------------------------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

long		ft_current_time(void);
long		ft_atol(const char *str);
void		ft_usleep(unsigned long micros);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_putstr_fd(char *s, int fd);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
size_t		ft_strlen(const char *s);

/*------------------------------------ Parsing -------------------------------*/

char		**parsing(int ac, char **av);
int			arr_len(char **arr);

/*-------------------------------- Errors checking ---------------------------*/

int			handle_input_errs(int len, char **args);
int			check_is_number(int ac, char **av);
int			check_max_int(int ac, char **av);
int			check_dup(int ac, char **av);
int			check_is_empty(int ac, char **av);
void		free_2d_arr(char **arr);

/*---------------------------------- Algo functions --------------------------*/

void		print_state(t_data *data, int time, int i, char *state);
void		thinking(t_data *data);
void		eating(t_data *data);
void		sleeping(t_data *data);
void		take_fork(t_data *data);
void		put_fork(t_data *data);
void		routine(t_data *data);
void		*child_routine(void *arg);

char		create_processes(t_data *data);
char		recipe(t_data *data);
#endif
