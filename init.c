/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:06 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/19 19:00:46 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void init_philo(t_philo *philo, int i, t_global *data)
{
	philo->fork_left = &data->forks[i];
	philo->fork_right = &data->forks[(i + 1) % data->n_philo];
	philo->id = i + 1;
	philo->last_food = 0;
	philo->num_food = 0;
	philo->global = data;
}