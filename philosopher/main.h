/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:47:23 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/02 17:01:11 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>

# include "parsing/parsing.h"

struct s_Timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
};

typedef struct s_Rules
{
	long long			number_of_philo;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			notepme;
	long long			time_start;
	int					status;
	pthread_mutex_t		status_mutex;
	pthread_t			dead_thread;
}	t_Rules;

typedef struct s_Forks
{
	int					fork_index;
	pthread_mutex_t		*mutex;
	struct s_Forks		*next;
	struct s_Forks		*prev;
}	t_Forks;

typedef struct s_Philos
{
	int					philo_index;
	pthread_t			thread;
	t_Rules				*rules;
	t_Forks				*forks;
	pthread_mutex_t		last_meal_mutex;
	long long			last_meal;
	int					number_of_meal;
	struct s_Philos		*next;
	struct s_Philos		*prev;
}	t_Philos;

typedef struct s_Structs
{
	t_Rules		*rules;
	t_Forks		*forks;
	t_Philos	*philos;
}	t_Structs;

void			log_fc(t_Philos *philos, int to_print, t_Rules *rules);
void			free_all(t_Structs *structs);
long long int	ft_atoll(const char *text);
void			join_threads(t_Philos *philos);
long long		timestamp(void);
void			sleeping(t_Philos *philos, t_Rules *rules);
int				eating(t_Forks *forks, t_Philos *philos, t_Rules *rules);
t_Forks			*find_fork(t_Philos *philos, t_Forks *forks);
void			*dead_thread_init(void *thread);
void			init_structs(t_Rules *rules, t_Philos *philos,
					t_Forks *forks, t_Structs *structs);
int				init_philo_lists(t_Philos **philos,
					t_Rules *rules, t_Forks *forks);
int				init_fork_lists(t_Forks **fork, t_Rules *rules);
void			init_rules_struct(t_Rules *rules, int argc, char **argv);
void			ft_usleep(size_t tmp);
int				check_meals(t_Philos *start, t_Rules *rules);
int				check_death(t_Philos *philo, t_Rules *rules);

#endif