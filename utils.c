/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:50:32 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/22 19:16:19 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_screen(char *str, long mls, int philo,int death)
{
	if (death == 0)
		printf("%ld %d %s\n", mls, philo, str);
}

void	msj_error(char *str, int error, t_global *data, t_philo *philos)
{
	if (data->forks)
		free(data->forks);
	if (philos)
		free(philos);
	printf("%s %d\n",str , error);
	exit(1);
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
