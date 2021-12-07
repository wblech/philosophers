/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:15:46 by wbertoni          #+#    #+#             */
/*   Updated: 2021/12/07 14:17:01 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_args *args)
{
	printf("%d %d %s\n", 0, 1, FORK);
	msleep(args->time_to_die);
	printf("%d %d %s\n", args->time_to_die, 1, DIE);
	exit(0);
}
