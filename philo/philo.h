#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef enum e_state
{
	SLEEPING,
	THINKING,
	EATING,
	DEAD,
}	t_state;

typedef struct s_args
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep ;
	int				number_of_times_each_philosopher_must_eat;
	bool			*forks;
	int				count_id;
	timeval			time_begin;
	pthread_mutex_t	mutex;
}	t_args;

typedef struct s_philo
{
	int		id;
	t_state	state;
	bool	left_fork;
	bool	right_fork;
	timeval	last_meal;
}	t_philo;

/*
** utils.c
*/
int		ft_atoi(const char *str);

/*
** philosopher.c
*/
void	*init_philo(void *args);
void	create_philo(t_philo *philo, t_args *args);
int		get_id(t_args *args);

/*
** philosopher.c
*/
double	get_time_diff(timeval begin, timeval end);
double	convert_to_ms(timeval begin);

#endif
