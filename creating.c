/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:56:07 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/22 15:36:08 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void *watching_philos(void *arg)
{
	t_philo *philo;
	int i;
	long	time;

	philo = (t_philo *)arg;
	while (philo->global->death == 0)
	{
		i = -1;
		while(++i < philo->global->n_philo)
		{
			time = get_time() - philo->global->time;
			if(philo[i].global->tt_die < (time - philo[i].last_food))
			{
				print_screen("die", (get_time() - philo->global->time), philo->id);
				philo->global->death = 1;
				return NULL;
			}
			if (philo[i].num_food == philo->global->quan_eat)
				return NULL;
		}
		usleep(50);
	}
	return(NULL);
}
void	creating_watcher(t_philo *philos, pthread_t *watcher)
{
	int res;

	res = pthread_create(watcher, NULL, watching_philos, (void *)philos);
	if (res != 0)
		msj_error("Error create thread",res, NULL, philos);
}

void	creating_forks(t_global *data)
{
	int i;
	int res;

	i = 0;
	res = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->n_philo);
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
