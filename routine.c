/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:14:19 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/22 19:23:50 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void *routine(void *arg)
{
	t_philo *philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_sleep(1);
	while (philo->global->death == 0 && philo->num_food < philo->global->quan_eat)
	{
		pthread_mutex_lock(philo->fork_left);
		print_screen("take fork left", (get_time() - philo->global->time), philo->id, philo->global->death);
		pthread_mutex_lock(philo->fork_right);
		print_screen("take fork right", (get_time() - philo->global->time), philo->id, philo->global->death);
		print_screen("is eating", (get_time() - philo->global->time), philo->id, philo->global->death);
		philo->last_food = get_time() - philo->global->time;
		philo->num_food++;
		ft_sleep(philo->global->tt_eat);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		print_screen("is sleeping", (get_time() - philo->global->time), philo->id, philo->global->death);
		ft_sleep(philo->global->tt_sleep);
		print_screen("is thinking",(get_time() - philo->global->time), philo->id, philo->global->death);
	}
	return NULL;
}
