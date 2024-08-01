/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:43 by misaguir          #+#    #+#             */
/*   Updated: 2024/08/01 11:34:12 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philosophers(t_global *data)
{
	pthread_t	watcher;
	t_philo		*philos;

	creating_forks(data);
	if (data->error == 1)
		return (1);
	if (data->n_philo == 1)
		philos = one_philo(data);
	if (!philos)
		return (1);
	else if (data->n_philo > 1)
	{
		philos = creating_thread(data);
		if (!philos)
			return (1);
		creating_watcher(philos, &watcher);
		if (data->error == 1)
			return (1);
		pthread_join(watcher, NULL);
		philo_joined(philos);
	}
	free(philos);
	free(data->forks);
	return (0);
}

static int	check_data(t_global *data)
{
	if (data->n_philo == -1 || data->quan_eat == -1
		|| data->tt_die == -1 || data->tt_eat == -1 || data->tt_sleep == -1)
	{
		write(2, "Error setting data\n", 19);
		return (1);
	}
	if (data->n_philo == 0)
	{
		write (2, "Error number philo\n", 20);
		return (1);
	}
	if (data->quan_eat == 0)
		return (0);
	return (2);
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
	data->error = 0;
	pthread_mutex_init(&data->death_t, NULL);
	pthread_mutex_init(&data->max_meal_t, NULL);
	pthread_mutex_init(&data->write, NULL);
	data->time = 0;
}

int	main(int argc, char **argv)
{
	t_global	data;

	init_global(&data);
	if (argc == 5 || argc == 6)
	{
		fill_in_data(&data, argv, argc);
		if (check_data(&data) == 2)
			return (philosophers(&data));
		else
			return (check_data(&data));
	}
	else
	{
		write(2, "Number arguments incorrect\n", 28);
		return (1);
	}
	return (0);
}
