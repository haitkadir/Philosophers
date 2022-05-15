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
# include <time.h>
# include <sys/time.h>
# include <stdio.h>
/*---------------------------------- Data struct ---------------------------*/
typedef struct s_data
{
	int				philos_len;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				total_meals;
	char			state;
	long			start_time;
	pthread_mutex_t	mutex;
}	t_data;
/*----------------------------- LInked list node -------------------------*/
typedef struct s_thread
{
	struct s_thread	*prev;
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				index;
	int				meals;
	t_data			*data;
	long			last_meal;
	struct s_thread	*next;
}	t_thread;
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
/*----------------------------- LInked list functions ------------------------*/
void		philoadd_back(t_thread **lst, t_thread *new);
void		philodelone(t_thread *lst);
t_thread	*philonew(t_data *data, int i);
t_thread	*philolast(t_thread *lst);
t_thread	*philolast(t_thread *lst);
int			philosize(t_thread *lst);
/*---------------------------------- Algo functions --------------------------*/
void		print_state(t_thread *thread, int time, int i, char *state);
void		thinking(t_thread *thread);
void		eating(t_thread *thread);
void		sleeping(t_thread *thread);
void		take_fork(t_thread *thread, int index);
void		put_fork(t_thread *thread);
void		*routine(void *args);

t_thread	*create_threads(t_data *data);
void		check_philos(t_thread *thread);
char		recipe(t_data *data);
#endif
