/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:56:07 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/23 10:31:16 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_philo *philo, int i, t_global *data)
{
	philo->fork_left = &data->forks[i];
	philo->fork_right = &data->forks[(i + 1) % data->n_philo];
	philo->id = i + 1;
	philo->last_food = 0;
	philo->num_food = 0;
	philo->global = data;
}

t_philo	*creating_thread(t_global *data)
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
		res = pthread_create(&(philos[i].thread), NULL,
				routine, (void *)&philos[i]);
		if (res != 0)
			msj_error("Error create thread", res, data, philos);
	}
	return (philos);
}

static void	*watching_philos(void *arg)
{
	t_philo	*philos;
	int		i;
	long	time;

	philos = (t_philo *)arg;
	while (philos->global->death == 0)
	{
		i = -1;
		while (++i < philos->global->n_philo)
		{
			time = get_time() - philos->global->time;
			if (philos[i].global->tt_die < (time - philos[i].last_food))
			{
				print_screen("died", (get_time() - philos->global->time),
					philos[i].id, philos->global->death);
				philos->global->death = 1;
				return (NULL);
			}
			if (philos[i].num_food == philos->global->quan_eat)
				return (NULL);
		}
		usleep(50);
	}
	return (NULL);
}

void	creating_watcher(t_philo *philos, pthread_t *watcher)
{
	int	res;

	res = pthread_create(watcher, NULL, watching_philos, (void *)philos);
	if (res != 0)
		msj_error("Error create thread", res, NULL, philos);
}

void	creating_forks(t_global *data)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->n_philo);
	if (!data->forks)
		return ;
	while (i < data->n_philo)
	{
		res = pthread_mutex_init(&data->forks[i], NULL);
		if (res != 0)
			msj_error("Error create forks", res, data, NULL);
		i++;
	}
}
