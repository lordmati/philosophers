/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:14:19 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/29 16:03:56 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->global->death_t);
	dead = philo->global->death;
	pthread_mutex_unlock(&philo->global->death_t);
	return (dead);
}

void	change_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->death_t);
	philo->global->death = 1;
	pthread_mutex_unlock(&philo->global->death_t);
}

static bool	entry_in_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->max_meal_t);
	if (philo->global->max_meal == false)
	{
		pthread_mutex_unlock(&philo->global->max_meal_t);
		return (true);
	}
	pthread_mutex_unlock(&philo->global->max_meal_t);
	pthread_mutex_lock(&philo->num_food_t);
	if (philo->num_food < philo->global->quan_eat)
	{
		pthread_mutex_unlock(&philo->num_food_t);
		return (true);
	}
	else
	{
		pthread_mutex_unlock(&philo->num_food_t);
		return (false);
	}
}

static void	locked_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->fork_left);
		print_screen(F, (get_time() - philo->global->time), philo->id,
			philo);
		pthread_mutex_lock(philo->fork_right);
		print_screen(F, (get_time() - philo->global->time), philo->id,
			philo);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		print_screen(F, (get_time() - philo->global->time), philo->id,
			philo);
		pthread_mutex_lock(philo->fork_left);
		print_screen(F, (get_time() - philo->global->time), philo->id,
			philo);
	}
	print_screen(E, (get_time() - philo->global->time), philo->id,
		philo);
	pthread_mutex_lock(&philo->last_food_t);
	philo->last_food = get_time() - philo->global->time;
	pthread_mutex_unlock(&philo->last_food_t);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_sleep(1);
	while (get_dead(philo) == 0 && (entry_in_routine(philo) == true))
	{
		locked_fork(philo);
		pthread_mutex_lock(&philo->num_food_t);
		philo->num_food++;
		pthread_mutex_unlock(&philo->num_food_t);
		ft_sleep(philo->global->tt_eat);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		print_screen(S, (get_time() - philo->global->time), philo->id,
			philo);
		ft_sleep(philo->global->tt_sleep);
		print_screen(T, (get_time() - philo->global->time), philo->id,
			philo);
	}
	return (NULL);
}
