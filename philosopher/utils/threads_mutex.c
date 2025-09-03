/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:24:44 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/02 16:11:18 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../main.h"

void	join_threads(t_Philos *philos)
{
	t_Philos	*tmp;
	int			i;

	if (!philos)
		return ;
	i = 0;
	tmp = philos;
	while (philos)
	{
		if (tmp == philos && i != 0)
			break ;
		pthread_join(philos->thread, NULL);
		philos = philos->prev;
		i = 1;
	}
}

int	check_death(t_Philos *philo, t_Rules *rules)
{
	pthread_mutex_lock(&philo->last_meal_mutex);
	if (timestamp() - philo->last_meal >= rules->time_to_die)
	{
		pthread_mutex_unlock(&philo->last_meal_mutex);
		log_fc(philo, 5, rules);
		pthread_mutex_lock(&rules->status_mutex);
		rules->status = 1;
		pthread_mutex_unlock(&rules->status_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (0);
}

int	check_meals(t_Philos *start, t_Rules *rules)
{
	t_Philos	*philo;
	int			i;

	if (rules->notepme == -1)
		return (0);
	philo = start;
	i = 0;
	while (i++ < rules->number_of_philo)
	{
		pthread_mutex_lock(&philo->last_meal_mutex);
		if (philo->number_of_meal < rules->notepme)
			return (pthread_mutex_unlock(&philo->last_meal_mutex), 0);
		pthread_mutex_unlock(&philo->last_meal_mutex);
		philo = philo->next;
	}
	pthread_mutex_lock(&rules->status_mutex);
	rules->status = 1;
	pthread_mutex_unlock(&rules->status_mutex);
	return (1);
}

void	*dead_thread_init(void *tmp)
{
	t_Structs	*structs;
	t_Philos	*philo;
	int			i;

	structs = (t_Structs *)tmp;
	ft_usleep(structs->rules->time_to_die);
	philo = structs->philos;
	i = 0;
	if (check_meals(structs->philos, structs->rules))
		return (NULL);
	while (i++ < structs->rules->number_of_philo)
	{
		if (check_death(philo, structs->rules))
			return (NULL);
		philo = philo->next;
	}
	return (NULL);
}
