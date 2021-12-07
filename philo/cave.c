/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:36:05 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 07:40:43 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->forks[philo->left_fork]);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->args->forks[philo->right_fork]);
	print_msg("has taken a fork", philo);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->args->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->args->forks[philo->right_fork]);
	philo->ate_time++;
}

bool	sleeping(t_philo *philo)
{
	if (!print_msg("is sleeping", philo))
		return (false);
	msleep(philo->args->time_to_sleeping);
	return (true);
}

bool	think(t_philo *philo)
{
	if (!print_msg("is thinking", philo))
		return (false);
	return (true);
}

bool	eat(t_philo *philo)
{
	if (is_not_worth_going_on(philo->args))
		return (false);
	get_fork(philo);
	philo->last_meal = elapsed_time(philo->args->time_begin);
	print_msg("is eating", philo);
	msleep(philo->args->time_to_eat);
	drop_forks(philo);
	if (full_tummy(philo))
		return (false);
	return (true);
}
