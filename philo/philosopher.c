/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:39:32 by coder             #+#    #+#             */
/*   Updated: 2021/10/14 19:40:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_id(t_args *args)
{
	int	id;

	pthread_mutex_lock(&args->mutex);
	id = args->count_id++;
	pthread_mutex_unlock(&args->mutex);
	return (id);
}

void	create_philo(t_philo *philo, t_args *args)
{
	philo->id = get_id(args);
	philo->state = EATING;
	philo->left_fork = false;
	philo->right_fork = false;
	philo->last_meal = args->time_begin;
}

timeval	execute_change_status(t_state state, char *str, t_philo *philo)
{
	timeval	begin;

	philo->state = state;
	gettimeofday(&begin, NULL);
	printf("%f %d %s", convert_to_ms(begin), philo->id, str);
	return (begin);
}

void	change_status(t_philo *philo, t_state state, t_args *args)
{
	if (state == DEAD)
		execute_change_status(state, "died", philo);
	else if (state == SLEEPING)
		execute_change_status(state, "is sleeping", philo);
	else if (state == THINKING)
		execute_change_status(state, "is thinking", philo);
	else if (state == EATING)
		philo->last_meal = convert_to_ms(
				execute_change_status(state, "is eating", philo));
}

bool	is_dead(t_philo *philo, t_args *args)
{
	double	diff;
	timeval	end;

	gettimeofday(&end, NULL);
	diff = get_time_diff(philo->last_meal, end);
	if (diff > args->time_to_die)
	{
		change_status(philo, DEAD);
		return (true);
	}
	return (false);
}

void	sleep(t_philo *philo, t_args *args)
{
	double	diff;
	timeval	begin;
	timeval	end;

	gettimeofday(&begin, NULL);
	diff = 0;
	while (diff < args->time_to_sleep)
	{
		if (is_dead(philo, args))
			return ;
		gettimeofday(&end, NULL);
		diff = get_time_diff(begin, end);
	}
	change_status(philo, args, THINKING);
}

void	think(t_philo *philo, t_args *args)
{
	int	i_left;
	int	i_right;

	if (philo->id == 1)
		i_left = args->number_of_philosophers - 1;
	else
		i_left = philo->id - 1;
	if (philo->id == args->number_of_philosophers - 1)
		i_right = 0;
	else
		i_right = philo->id + 1;
	while (!philo->left_fork && !philo->right_fork && !is_dead(&philo))
	{
		if (args->forks[i_left] && args->forks[i_right])
		{
			philo->left_fork = true;
			philo->right_fork = true;
		}
	}
	change_status(philo, EATING);
}

void	*init_philo(void *args)
{
	t_philo	philo;

	create_philo(&philo, args);
	while (philo.status != DEAD)
	{
		if (philo.status == SLEEP)
			sleep(&philo);
		else if (philo.status == EATING)
			eat();
		else
			think(&philo);
	}
	return (NULL);
}
