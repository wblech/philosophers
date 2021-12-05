/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:58:52 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/05 20:17:48 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_msg(char *str, t_philo *philo, t_args *args)
{
	pthread_mutex_lock(&args->print);
	if (is_not_worth_going_on(*args))
	{
		pthread_mutex_unlock(&args->print);
		return (false);
	}
	printf("%11lld %d %s\n", get_current_time(), philo->id, str);
	pthread_mutex_unlock(&args->print);
	return (true);
}
