/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:58:52 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/05 19:59:13 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_msg(char *str, t_philo *philo, t_args *args)
{
	struct timeval	begin;

	pthread_mutex_lock(&args->print);
	if (is_not_worth_going_on(*args))
	{
		pthread_mutex_unlock(&args->print);
		return (false);
	}
	gettimeofday(&begin, NULL);
	printf("%11ld %d %s\n", current_time(begin), philo->id, str);
	pthread_mutex_unlock(&args->print);
	return (true);
}
