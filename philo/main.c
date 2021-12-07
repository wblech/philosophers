/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:01:23 by coder             #+#    #+#             */
/*   Updated: 2021/12/07 14:25:21 by wbertoni         ###   ########.fr       */
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
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleeping = ft_atoi(argv[4]);
	if (argc > 5)
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		args->number_of_times_each_philosopher_must_eat = 0;
	args->count_id = 1;
	args->time_begin = 0;
	args->forks = (pthread_mutex_t *)malloc(args->number_of_philosophers
			* sizeof(pthread_mutex_t));
	args->td = NULL;
	args->is_over = false;
}

void	check_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: You should give 4 obligatory arguments and 1 optional: \
number_of_philosophers, time_to_die, time_to_eat, time_to_sleeping,\
[number_of_times_each_philosopher_must_eat]\n");
		exit(1);
	}
}

void	create_mutex(t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_init(&args->mutex, NULL);
	pthread_mutex_init(&args->print, NULL);
	pthread_mutex_init(&args->death, NULL);
	while (i < args->number_of_philosophers)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_args		args;
	t_philo		*philo;

	i = 0;
	check_args(argc);
	init_args(&args, argc, argv);
	if (args.number_of_philosophers == 1)
		one_philo(&args);
	create_mutex(&args);
	philo = create_philosophers(&args);
	start_real_life(philo, &args);
	while (i < args.number_of_philosophers)
	{
		pthread_join(args.td[i], NULL);
		i++;
	}
	free_all_and_destroy(philo, &args);
	return (0);
}
