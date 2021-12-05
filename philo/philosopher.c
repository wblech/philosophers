/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:39:32 by coder             #+#    #+#             */
/*   Updated: 2021/12/05 20:16:19 by wbertoni         ###   ########.fr       */
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
	if (philo->id == 1)
		philo->left_fork = 0;
	else
		philo->left_fork = philo->id;
	if (philo->id == args->number_of_philosophers)
		philo->right_fork = 0;
	else
		philo->right_fork = philo->id + 1;
	philo->last_meal = args->time_begin;
	philo->ate_time = 0;
}

t_thread_of_life	*parcae(t_philo *philo, t_args *args)
{
	t_thread_of_life	*thread_of_life;

	thread_of_life = (t_thread_of_life *)malloc(1 * sizeof(t_thread_of_life));
	thread_of_life->args = args;
	thread_of_life->philo = philo;
	return (thread_of_life);
}

void	*silver_cloud(void *thread_of_life)
{
	t_thread_of_life	*thread;

	thread = (t_thread_of_life *)thread_of_life;
	while (!has_death_arrived(thread->philo, thread->args))
		continue ;
	return (NULL);
}

void	*init_philo(void *args)
{
	t_philo				philo;
	pthread_t			thanatos;
	t_thread_of_life	*thread_of_life;

	create_philo(&philo, args);
	thread_of_life = parcae(&philo, args);
	pthread_create(&thanatos, NULL, &silver_cloud, &thread_of_life);
	pthread_detach(thanatos);
	while (eat(&philo, args) || sleeping(&philo, args) || think(&philo, args))
		continue ;
	return (NULL);
}
