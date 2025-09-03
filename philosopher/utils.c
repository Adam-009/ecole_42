/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:13:01 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/01 18:21:55 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

t_Forks	*find_fork(t_Philos *philos, t_Forks *forks)
{
	while (forks->fork_index != philos->philo_index)
		forks = forks->next;
	return (forks);
}

void	free_philo(t_Philos *list)
{
	t_Philos	*tmp;
	t_Philos	*first;
	int			i;

	i = 0;
	first = list;
	while (list)
	{
		if (list == first && i != 0)
			return ;
		i = 1;
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	free_fork(t_Forks *list)
{
	t_Forks	*tmp;
	t_Forks	*first;
	int		i;

	i = 0;
	first = list;
	while (list)
	{
		if (list == first && i != 0)
			break ;
		i = 1;
		tmp = list;
		list = list->next;
		if (tmp->mutex)
		{
			pthread_mutex_destroy(tmp->mutex);
			free(tmp->mutex);
		}
		free(tmp);
	}
}

void	free_all(t_Structs *structs)
{
	pthread_mutex_destroy(&structs->rules->status_mutex);
	pthread_mutex_destroy(&structs->philos->last_meal_mutex);
	free_philo(structs->philos);
	free_fork(structs->forks);
	free(structs->rules);
	free(structs);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
