/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:44:22 by misaguir          #+#    #+#             */
/*   Updated: 2024/07/30 13:50:32 by misaguir         ###   ########.fr       */
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
# include <stdbool.h>

# define F "has taken a fork"
# define E "is eating"
# define S "is sleeping"
# define T "is thinking"

typedef struct s_global
{
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				quan_eat;
	bool			max_meal;
	int				death;
	int				error;
	pthread_mutex_t	max_meal_t;
	pthread_mutex_t	death_t;
	pthread_mutex_t	write;
	long			time;
	pthread_mutex_t	*forks;
}	t_global;

typedef struct s_philo
{
	int				id;
	long			last_food;
	int				num_food;
	pthread_mutex_t	last_food_t;
	pthread_mutex_t	num_food_t;
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
void	print_screen(char *str, long mls, int id, t_philo *philo);
long	get_time(void);
void	creating_watcher(t_philo *philos, pthread_t *watcher);
void	ft_sleep(long mls);
t_philo	*creating_thread(t_global *data);
int		get_dead(t_philo *philo);
void	change_death(t_philo *philo);
t_philo	*one_philo(t_global *data);
void	init_philo(t_philo *philo, int i, t_global *data);
int		check_death(t_philo *philos, long time, int i);
void	philo_joined(t_philo *philos);

#endif