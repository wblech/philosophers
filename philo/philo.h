/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 02:25:11 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 15:14:55 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork"
# define DIE "die"

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
	pthread_t		*td;
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
	t_args	*args;
}	t_philo;

/*
** utils.c
*/
int				ft_atoi(const char *str);
bool			ft_isdigit(int c);

/*
** real_life.c
*/
void			*real_life(void *args);
t_philo			*create_philo(t_philo *philo, t_args *args, int index);

/*
** real_life.c
*/
t_philo			*create_philosophers(t_args *args);
void			start_real_life(t_philo *philo, t_args *args);

/*
** time.c
*/
long long int	get_current_time(void);
long long int	elapsed_time(long long int start_time);
int				msleep(long long int time_in_ms);

/*
** thanatos.c
*/
bool			full_tummy(t_philo *philo);
bool			is_not_worth_going_on(t_args *args);
bool			has_death_arrived(t_philo *philo);

/*
** print_msg.c
*/
bool			print_msg(char *str, t_philo *philo);

/*
** cave.c
*/
bool			sleeping(t_philo *philo);
bool			think(t_philo *philo);
bool			eat(t_philo *philo);

/*
** free_all_and_destroy.c
*/
void			free_all_and_destroy(t_philo *philosophers, t_args *args);

/*
** one_philo.c
*/
void			one_philo(t_args *args);

#endif
