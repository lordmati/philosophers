/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:43 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/16 17:51:15 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void check_data(t_philo *data)
{
	if (data->n_philo == -1 || data->n_of_t_each_philo_must_eat == -1
		|| data->tt_die == -1 || data->tt_eat == -1 || data->tt_sleep == -1)
	{
		printf("Error setting data\n");
		exit(1);
	}
	if (data->n_philo == 0)
	{
		printf("Error number philo\n");
		exit(1);
	}
	if (data->n_of_t_each_philo_must_eat == 0)
		exit(0);
}

static void fill_in_data(t_philo *data,char **argv, int argc)
{
	data->n_philo = ft_atol(argv[1]);
	data->tt_die = ft_atol(argv[2]);
	data->tt_eat = ft_atol(argv[3]);
	data->tt_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->n_of_t_each_philo_must_eat = ft_atol(argv[5]);
}

static void init_philo(t_philo *data)
{
	data->n_philo = -2;
	data->tt_die = -2;
	data->tt_eat = -2;
	data->tt_sleep = -2;
	data->n_of_t_each_philo_must_eat = -2;
}

int main (int argc, char **argv)
{
	t_philo data;
	init_philo(&data);
	if (argc == 5 || argc == 6)
	{
		fill_in_data(&data, argv, argc);
		check_data(&data);
	}
	else
		printf("Number arguments incorrect\n");
	return(0);
}