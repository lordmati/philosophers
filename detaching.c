/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detaching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:47:26 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/22 19:15:33 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(long mls)
{
	long start;
	start = get_time();
	while (get_time() - start < mls)
		usleep(100);
}

void	philo_joined(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos->global->n_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
