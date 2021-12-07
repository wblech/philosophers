/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:17:44 by coder             #+#    #+#             */
/*   Updated: 2021/12/07 15:07:02 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	count_minus;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	count_minus = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count_minus = 1;
		i++;
	}
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (count_minus > 0)
		n = n * (-1);
	return (n);
}
