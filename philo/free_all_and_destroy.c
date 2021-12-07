/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:39:32 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 13:40:02 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all_and_destroy(t_philo *philosophers, t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&args->mutex);
	pthread_mutex_destroy(&args->print);
	pthread_mutex_destroy(&args->death);
	while (i < args->number_of_philosophers)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	free (philosophers);
	free (args->td);
	free (args->forks);
}
