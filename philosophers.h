/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:44:22 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/22 19:17:18 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_global
{
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				quan_eat;
	int				death;
	long			time;
	pthread_mutex_t	*forks;
}	t_global;

typedef struct s_philo
{
	int				id;
	long			last_food;
	int				num_food;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	t_global		*global;
	pthread_t		thread;
}	t_philo;

////////FUNCTIONS////////
long	ft_atol(const char *str);
void	msj_error(char *str, int error, t_global *data, t_philo *philos);
void	creating_forks(t_global *data);
void	*routine(void *arg);
void	print_screen(char *str, long mls, int philo, int death);
long	get_time(void);
void	init_philo(t_philo *philo, int i, t_global *data);
void	creating_watcher(t_philo *philos, pthread_t *watcher);
void	philo_joined(t_philo *philos);
void	ft_sleep(long mls);


#endif