/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_watching.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:51:04 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/29 16:05:55 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death(t_philo *philos, long time, int i)
{
	pthread_mutex_lock(&philos[i].last_food_t);
	if (philos[i].global->tt_die < (time - philos[i].last_food))
	{
		pthread_mutex_unlock(&philos[i].last_food_t);
		print_screen("died", (get_time() - philos->global->time),
			philos[i].id, &philos[i]);
		change_death(&philos[i]);
		return (0);
	}
	pthread_mutex_unlock(&philos[i].last_food_t);
	return (1);
}
