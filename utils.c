/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:50:32 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/30 14:24:15 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(long mls)
{
	long	start;

	start = get_time();
	while (get_time() - start < mls)
		usleep(100);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_screen(char *str, long mls, int id, t_philo *philo)
{
	if (get_dead(philo) == 0)
	{
		pthread_mutex_lock(&philo->global->write);
		printf("%ld %d %s\n", mls, id, str);
		pthread_mutex_unlock(&philo->global->write);
	}
}

void	msj_error(char *str, int error, t_global *data, t_philo *philos)
{
	if (data->forks)
		free(data->forks);
	if (philos)
		free(philos);
	write(2, str, ft_strlen(str));
	printf("Error: %d\n", error);
	data->error = 1;
}

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		sig;

	sig = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0' && sig == 1)
		return (num);
	else
		return (-1);
}
