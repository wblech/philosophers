/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:54:00 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 08:03:43 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thread_of_life	*parcae(t_philo *philo, t_args *args)
{
	t_thread_of_life	*thread_of_life;

	thread_of_life = (t_thread_of_life *)malloc(1 * sizeof(t_thread_of_life));
	thread_of_life->args = args;
	thread_of_life->philo = philo;
	return (thread_of_life);
}

void	*silver_cloud(void *persona)
{
	t_philo	*philo;

	philo = (t_philo *)persona;
	while (!has_death_arrived(philo))
		continue ;
	return (NULL);
}

static bool	is_even(int philo)
{
	if (philo % 2 == 0)
		return (true);
	return (false);
}

void	*real_life(void *persona)
{
	pthread_t			thanatos;
	t_philo				*philo;

	philo = (t_philo *)persona;
	if (is_even(philo->id))
		msleep(5);
	pthread_create(&thanatos, NULL, &silver_cloud, philo);
	pthread_detach(thanatos);
	while (eat(philo) && sleeping(philo) && think(philo))
		continue ;
	return (NULL);
}
