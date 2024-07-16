/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:44:22 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/16 16:58:00 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo
{
	int		n_philo;
	int		tt_die;
	int		tt_eat;
	int		tt_sleep;
	int		n_of_t_each_philo_must_eat;
}	t_philo;


////////FUNCTIONS////////
long	ft_atol(const char *str);


#endif