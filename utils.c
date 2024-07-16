/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:50:32 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/16 17:35:38 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
