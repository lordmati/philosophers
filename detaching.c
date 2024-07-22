/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detaching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:47:26 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/22 16:50:34 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_joined(t_philo **philos)
{
	int i;

	i = 0;
	while (i < philos[i]->global->n_philo)
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
}