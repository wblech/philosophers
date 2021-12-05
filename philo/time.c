/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:59 by coder             #+#    #+#             */
/*   Updated: 2021/12/05 18:50:20 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_time_diff(struct timeval begin, struct timeval end)
{
	return ((end.tv_sec - begin.tv_sec) * 1000
		+ (end.tv_usec - begin.tv_usec) / 1000);
}

long long int	convert_to_ms(struct timeval begin)
{
	return ((begin.tv_sec * 1000) + begin.tv_usec / 1000);
}

long long int	diff_ms(double begin, double end)
{
	return (end - begin);
}

long long int	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
