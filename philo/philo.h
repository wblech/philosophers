#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleeping ;
	int				number_of_times_each_philosopher_must_eat;
	int				count_id;
	double			time_begin;
	bool			is_over;
	int				who_died;
	int				time_of_death;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	*forks;
}	t_args;

typedef struct s_philo
{
	int		id;
	int		left_fork;
	int		right_fork;
	double	last_meal;
	int		ate_time;
}	t_philo;

typedef struct s_thread_of_life
{
	t_philo	*philo;
	t_args	*args;
}	t_thread_of_life;

/*
** utils.c
*/
int				ft_atoi(const char *str);

/*
** philosopher.c
*/
void			*init_philo(void *args);
void			create_philo(t_philo *philo, t_args *args);
int				get_id(t_args *args);
void			*silver_cloud(void *thread_of_life);

/*
** time.c
*/
long long int	get_time_diff(struct timeval begin, struct timeval end);
long long int	convert_to_ms(struct timeval begin);
long long int	diff_ms(double begin, double end);
long long int	get_current_time(void);

/*
** thanatos.c
*/
bool			full_tummy(t_philo philo, t_args args);
bool			is_not_worth_going_on(t_args args);
bool	has_death_arrived(t_philo *philo, t_args *args);

/*
** print_msg.c
*/
bool			print_msg(char *str, t_philo *philo, t_args *args);

/*
** cave.c
*/
bool			sleeping(t_philo *philo, t_args *args);
bool			think(t_philo *philo, t_args *args);
bool			eat(t_philo *philo, t_args *args);
#endif
