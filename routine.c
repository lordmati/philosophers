/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:14:19 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/23 11:31:35 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	entry_in_routine(t_philo *philo)
{
	if (philo->global->max_meal == false)
		return (true);
	else if (philo->num_food < philo->global->quan_eat)
		return (true);
	else
		return (false);
}

static void	save_mutex_print(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_screen(F, (get_time() - philo->global->time), philo->id,
		philo->global->death);
	pthread_mutex_lock(philo->fork_right);
	print_screen(F, (get_time() - philo->global->time), philo->id,
		philo->global->death);
	print_screen(E, (get_time() - philo->global->time), philo->id,
		philo->global->death);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_sleep(1);
	while (philo->global->death == 0
		&& (entry_in_routine(philo) == true))
	{
		save_mutex_print(philo);
		philo->last_food = get_time() - philo->global->time;
		philo->num_food++;
		ft_sleep(philo->global->tt_eat);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		print_screen(S, (get_time() - philo->global->time), philo->id,
			philo->global->death);
		ft_sleep(philo->global->tt_sleep);
		print_screen(T, (get_time() - philo->global->time), philo->id,
			philo->global->death);
	}
	return (NULL);
}
