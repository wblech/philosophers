/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:55:52 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 06:37:37 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philosophers(t_args *args)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(args->number_of_philosophers
			* sizeof(t_philo));
	while (i < args->number_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = philo[i].id - 1;
		philo[i].right_fork = (i + 1) % args->number_of_philosophers;
		philo[i].last_meal = 0;
		philo[i].ate_time = 0;
		philo[i].args = args;
		i++;
	}
	return (philo);
}
