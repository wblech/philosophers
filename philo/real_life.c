/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:54:00 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 14:29:12 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_t	*thread_id_arr(int size)
{
	pthread_t	*td;

	td = (pthread_t *)malloc(size * sizeof(pthread_t));
	return (td);
}

static void	*silver_cloud(void *persona)
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

void	start_real_life(t_philo *philo, t_args *args)
{
	int			i;
	pthread_t	*td;

	i = 0;
	td = thread_id_arr(args->number_of_philosophers);
	args->td = td;
	args->time_begin = get_current_time();
	while (i < args->number_of_philosophers)
	{
		pthread_create(&td[i], NULL, &real_life, &philo[i]);
		i++;
	}
}
