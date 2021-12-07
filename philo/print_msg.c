/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:58:52 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 07:41:21 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_msg(char *str, t_philo *philo)
{
	if (is_not_worth_going_on(philo->args))
		return (false);
	pthread_mutex_lock(&philo->args->print);
	printf("%lld %d %s\n", elapsed_time(philo->args->time_begin),
		philo->id, str);
	pthread_mutex_unlock(&philo->args->print);
	return (true);
}
