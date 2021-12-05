/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:36:05 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/05 20:16:36 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_fork(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&args->forks[philo->left_fork]);
	print_msg("has taken a fork", philo, args);
	pthread_mutex_lock(&args->forks[philo->right_fork]);
	print_msg("has taken a fork", philo, args);
}

static void	drop_forks(t_philo *philo, t_args *args)
{
	pthread_mutex_unlock(&args->forks[philo->left_fork]);
	pthread_mutex_unlock(&args->forks[philo->right_fork]);
	philo->ate_time++;
}

bool	sleeping(t_philo *philo, t_args *args)
{
	if (!print_msg("is sleepinging", philo, args))
		return (false);
	usleep(args->time_to_sleeping);
	return (true);
}

bool	think(t_philo *philo, t_args *args)
{
	return (print_msg("is thinking", philo, args));
}

bool	eat(t_philo *philo, t_args *args)
{
	if (is_not_worth_going_on(*args))
		return (false);
	get_fork(philo, args);
	usleep(args->time_to_eat);
	drop_forks(philo, args);
	if (full_tummy(*philo, *args))
		return (false);
	return (true);
}
