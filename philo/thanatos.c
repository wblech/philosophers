/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thanatos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:30:53 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 13:59:09 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	full_tummy(t_philo *philo)
{
	if (philo->args->number_of_times_each_philosopher_must_eat != 0
		&& philo->ate_time
		>= philo->args->number_of_times_each_philosopher_must_eat)
		return (true);
	return (false);
}

bool	starved_to_death(t_philo *philo)
{
	long long int	now;

	now = elapsed_time(philo->args->time_begin);
	if ((now - philo->last_meal) >= philo->args->time_to_die)
	{
		pthread_mutex_lock(&philo->args->death);
		print_msg(DIE, philo);
		philo->args->is_over = true;
		pthread_mutex_unlock(&philo->args->death);
		return (true);
	}
	return (false);
}

bool	is_not_worth_going_on(t_args *args)
{
	return (args->is_over);
}

bool	has_death_arrived(t_philo *philo)
{
	long long int	now;

	if (is_not_worth_going_on(philo->args) || full_tummy(philo))
		return (true);
	now = elapsed_time(philo->args->time_begin);
	if ((now - philo->last_meal) >= philo->args->time_to_die)
	{
		pthread_mutex_lock(&philo->args->death);
		print_msg("died", philo);
		philo->args->is_over = true;
		pthread_mutex_unlock(&philo->args->death);
		return (true);
	}
	return (false);
}
