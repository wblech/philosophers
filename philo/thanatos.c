/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thanatos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:30:53 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/05 20:03:15 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	full_tummy(t_philo philo, t_args args)
{
	if (args.number_of_times_each_philosopher_must_eat != 0
		&& philo.ate_time >= args.number_of_times_each_philosopher_must_eat)
		return (true);
	return (false);
}

void	kill_philo(t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&args->death);
	if (is_not_worth_going_on(*args))
		return ;
	print_msg("died", philo, args);
	args->is_over = true;
	pthread_mutex_unlock(&args->death);
}

bool	starved_to_death(t_philo *philo, t_args *args)
{
	long long int	now;

	now = get_current_time();
	if ((now - philo->last_meal) >= args->time_to_die)
	{
		kill_philo(philo, args);
		return (true);
	}
	return (false);
}

bool	is_not_worth_going_on(t_args args)
{
	return (args.is_over);
}

bool	has_death_arrived(t_philo *philo, t_args *args)
{
	if (is_not_worth_going_on(*args)
		|| starved_to_death(philo, args)
		|| full_tummy(*philo, *args))
		return (true);
	return (false);
}
