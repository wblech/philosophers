/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:59 by coder             #+#    #+#             */
/*   Updated: 2021/10/14 17:19:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	get_time_diff(timeval begin, timeval end)
{
	return ((end.tv_sec - begin.tv_sec) * 1000000
		+ end.tv_usec - begin.tv_usec);
}

double	convert_to_ms(timeval begin)
{
	return ((begin.tv_sec * 1000000) + begin.tv_usec);
}
