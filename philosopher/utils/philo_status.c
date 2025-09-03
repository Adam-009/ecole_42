/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:03:40 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/02 17:08:18 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../main.h"

void	sleeping(t_Philos *philos, t_Rules *rules)
{
	pthread_mutex_lock(&rules->status_mutex);
	if (rules->status == 1)
	{
		pthread_mutex_unlock(&rules->status_mutex);
		return ;
	}
	pthread_mutex_unlock(&rules->status_mutex);
	log_fc(philos, 3, rules);
	ft_usleep(rules->time_to_sleep);
	pthread_mutex_lock(&rules->status_mutex);
	if (rules->status == 1)
	{
		pthread_mutex_unlock(&rules->status_mutex);
		return ;
	}
	pthread_mutex_unlock(&rules->status_mutex);
	if (rules->number_of_philo % 2 != 0)
		ft_usleep(1);
	log_fc(philos, 4, rules);
}

void	mutex_unlock(t_Forks *fork1, t_Forks *fork2)
{
	pthread_mutex_unlock(fork1->mutex);
	if (fork2)
		pthread_mutex_unlock(fork2->mutex);
}

void	mutex_lock(t_Forks	*forks, t_Rules *rules, t_Philos *philos, int i)
{
	if (i == 1)
	{
		pthread_mutex_lock(forks->mutex);
		log_fc(philos, 1, rules);
		pthread_mutex_lock(forks->prev->mutex);
		log_fc(philos, 1, rules);
	}
	else
	{
		pthread_mutex_lock(forks->prev->mutex);
		log_fc(philos, 1, rules);
		pthread_mutex_lock(forks->mutex);
		log_fc(philos, 1, rules);
	}
}

int	eating(t_Forks *forks, t_Philos *philos, t_Rules *rules)
{
	t_Forks	*r_forks;

	if (check_death(philos, rules) == 1)
		return (1);
	r_forks = find_fork(philos, forks);
	if (rules->number_of_philo == 1)
	{
		log_fc(philos, 1, rules);
		ft_usleep(rules->time_to_die);
		return (1);
	}
	if (philos->philo_index % 2 == 0)
		mutex_lock(r_forks, rules, philos, 1);
	else
		mutex_lock(r_forks, rules, philos, 2);
	log_fc(philos, 2, rules);
	pthread_mutex_lock(&philos->last_meal_mutex);
	philos->last_meal = timestamp();
	philos->number_of_meal++;
	pthread_mutex_unlock(&philos->last_meal_mutex);
	if (check_meals(philos, rules) == 1)
		return (mutex_unlock(r_forks, r_forks->prev), 1);
	ft_usleep(rules->time_to_eat);
	mutex_unlock(r_forks, r_forks->prev);
	return (0);
}

void	log_fc(t_Philos *philos, int to_print, t_Rules *rules)
{
	pthread_mutex_lock(&rules->status_mutex);
	if (to_print == 1 && rules->status != 1)
		printf("%lld %i has taken a fork\n",
			(timestamp() - rules->time_start), philos->philo_index);
	if (to_print == 2 && rules->status != 1)
		printf("%lld %i is eating\n",
			(timestamp() - rules->time_start), philos->philo_index);
	if (to_print == 3 && rules->status != 1)
		printf("%lld %i is sleeping\n",
			(timestamp() - rules->time_start), philos->philo_index);
	if (to_print == 4 && rules->status != 1)
		printf("%lld %i is thinking\n",
			(timestamp() - rules->time_start), philos->philo_index);
	if (to_print == 5 && rules->status != 1)
	{
		printf("%lld %i died\n",
			(timestamp() - rules->time_start), philos->philo_index);
		rules->status = 1;
	}
	pthread_mutex_unlock(&rules->status_mutex);
}
