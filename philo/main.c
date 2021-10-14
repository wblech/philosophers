/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:01:23 by coder             #+#    #+#             */
/*   Updated: 2021/10/14 17:09:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	*thread_id_arr(int size)
{
	pthread_t	*td;

	td = (pthread_t *)malloc(size * sizeof(pthread_t));
	return (td);
}

void	init_args(t_args *args, int argc, char *argv[])
{
	timeval	begin;

	gettimeofday(&begin, NULL);
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		args->number_of_times_each_philosopher_must_eat = -1;
	args->forks = NULL;
	args->count_id = 0;
	args->time_begin = begin;
}

void	check_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: You should give 4 obligatory arguments and 1 optional: \
number_of_philosophers, time_to_die, time_to_eat, time_to_sleep,\
[number_of_times_each_philosopher_must_eat]\n");
		exit(1);
	}
}

/*
**	number_of_philosophers time_to_die time_to_eat
**  time_to_sleep [number_of_times_each_philosopher_must_eat]
*/
int	main(int argc, char *argv[])
{
	pthread_t	*td;
	int			i;
	t_args		args;
	bool		*forks;

	i = 0;
	check_args(argc);
	init_args(&args, argc, argv);
	td = thread_id_arr(args.number_of_philosophers);
	forks = (bool *)malloc(args.number_of_philosophers * sizeof(bool));
	args.forks = forks;
	pthread_mutex_init(&args.mutex, NULL);
	while (i < args.number_of_philosophers)
	{
		pthread_create(&td[i], NULL, &init_philo, &args);
		i++;
	}
	i = 0;
	while (i < args.number_of_philosophers)
	{
		pthread_join(td[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&args.mutex);
	free(forks);
	free(td);
	return (0);
}
