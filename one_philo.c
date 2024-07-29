/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:30:33 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/29 16:02:47 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*routine_one_philo(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->fork_left);
	print_screen(F, (get_time() - philo->global->time), philo->id, philo);
	pthread_mutex_unlock(philo->fork_left);
	usleep(philo->global->tt_die * 1000);
	print_screen("died", (get_time() - philo->global->time), philo->id, philo);
	return (NULL);
}

t_philo	*one_philo(t_global *data)
{
	int			i;
	int			res;
	t_philo		*philos;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philo);
	if (!philos)
		return (NULL);
	while (++i < data->n_philo)
		init_philo(&philos[i], i, data);
	i = -1;
	data->time = get_time();
	while (++i < data->n_philo)
	{
		res = pthread_create(&(philos[i].thread), NULL,
				routine_one_philo, (void *)&philos[i]);
		if (res != 0)
			msj_error("Error create thread", res, data, philos);
	}
	pthread_join(philos[0].thread, NULL);
	return (philos);
}
