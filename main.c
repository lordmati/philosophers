/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:43 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/29 16:02:25 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_joined(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->global->n_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return ;
}

static void	check_data(t_global *data)
{
	if (data->n_philo == -1 || data->quan_eat == -1
		|| data->tt_die == -1 || data->tt_eat == -1 || data->tt_sleep == -1)
	{
		printf("Error setting data\n");
		exit(1);
	}
	if (data->n_philo == 0)
	{
		printf("Error number philo\n");
		exit(1);
	}
	if (data->quan_eat == 0)
		exit(0);
}

static void	fill_in_data(t_global *data, char **argv, int argc)
{
	data->n_philo = ft_atol(argv[1]);
	data->tt_die = ft_atol(argv[2]);
	data->tt_eat = ft_atol(argv[3]);
	data->tt_sleep = ft_atol(argv[4]);
	data->max_meal = false;
	if (argc == 6)
	{
		data->max_meal = true;
		data->quan_eat = ft_atol(argv[5]);
	}
}

static void	init_global(t_global *data)
{
	data->n_philo = -2;
	data->tt_die = -2;
	data->tt_eat = -2;
	data->tt_sleep = -2;
	data->quan_eat = -2;
	data->death = 0;
	data->forks = NULL;
	pthread_mutex_init(&data->death_t, NULL);
	pthread_mutex_init(&data->max_meal_t, NULL);
	pthread_mutex_init(&data->write, NULL);
	data->time = 0;
}

int	main(int argc, char **argv)
{
	t_global	data;
	t_philo		*philos;
	pthread_t	watcher;

	init_global(&data);
	if (argc == 5 || argc == 6)
	{
		fill_in_data(&data, argv, argc);
		check_data(&data);
		creating_forks(&data);
		if (data.n_philo == 1)
			philos = one_philo(&data);
		else
		{
			philos = creating_thread(&data);
			creating_watcher(philos, &watcher);
			pthread_join(watcher, NULL);
			philo_joined(philos);
		}
		free(philos);
		free(data.forks);
	}
	else
		printf("Number arguments incorrect\n");
	return (0);
}
