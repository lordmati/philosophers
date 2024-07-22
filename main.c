/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:43 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/22 19:09:04 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo *creating_thread(t_global *data)
{
	int			i;
	int			res;
	t_philo		*philos;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philo + 1);
	if (!philos)
		return (NULL);
	while (++i < data->n_philo)
		init_philo(&philos[i], i, data);
	i = -1;
	data->time = get_time();
	while (++i < data->n_philo)
	{
		res = pthread_create(&(philos[i].thread), NULL, routine, (void *)&philos[i]);
		if (res != 0)
			msj_error("Error create thread", res, data, philos);
	}
	return (philos);
}

static void check_data(t_global *data)
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

static void fill_in_data(t_global *data,char **argv, int argc)
{
	data->n_philo = ft_atol(argv[1]);
	data->tt_die = ft_atol(argv[2]);
	data->tt_eat = ft_atol(argv[3]);
	data->tt_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->quan_eat = ft_atol(argv[5]);
}

static void init_global(t_global *data)
{
	data->n_philo = -2;
	data->tt_die = -2;
	data->tt_eat = -2;
	data->tt_sleep = -2;
	data->quan_eat = -2;
	data->death = 0;
	data->forks = NULL;
	data->time = 0;
}

int main (int argc, char **argv)
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
		philos = creating_thread(&data);
		creating_watcher(philos, &watcher);
		pthread_join(watcher, NULL);
		philo_joined(philos);
		free(philos);
		free(data.forks);
	}
	else
		printf("Number arguments incorrect\n");
	return(0);
}
