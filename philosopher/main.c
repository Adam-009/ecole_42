/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:03:12 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/02 15:57:46 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*philosopher(void *arg)
{
	t_Philos	*philo;

	philo = (t_Philos *)arg;
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (philo->philo_index % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(&philo->rules->status_mutex);
	while (philo->rules->status == 0)
	{
		pthread_mutex_unlock(&philo->rules->status_mutex);
		if (philo->rules->notepme != -1
			&& philo->rules->notepme == philo->number_of_meal)
			return (NULL);
		if (eating(philo->forks, philo, philo->rules) == 1)
			return (NULL);
		if (check_meals(philo, philo->rules) == 1)
			return (NULL);
		sleeping(philo, philo->rules);
		pthread_mutex_lock(&philo->rules->status_mutex);
	}
	pthread_mutex_unlock(&philo->rules->status_mutex);
	return (NULL);
}

int	thread_init(t_Structs *structs)
{
	t_Philos	*philo;
	int			i;

	i = 0;
	philo = structs->philos;
	while (i++ < structs->rules->number_of_philo)
	{
		if (pthread_create(&philo->thread, NULL, philosopher, (void *)philo)
			!= 0)
			return (1);
		philo = philo->next;
	}
	pthread_create(&structs->rules->dead_thread, NULL, dead_thread_init,
		(void *)structs);
	join_threads(structs->philos);
	pthread_join(structs->rules->dead_thread, NULL);
	return (0);
}

void	ft_usleep(size_t tmp)
{
	size_t	time;

	time = timestamp();
	while ((timestamp() - time) < tmp)
		usleep(tmp / 10);
}

int	main(int argc, char **argv)
{
	t_Forks			*forks;
	t_Rules			*rules;
	t_Philos		*philos;
	t_Structs		*structs;

	forks = NULL;
	philos = NULL;
	structs = NULL;
	rules = NULL;
	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments\n"), 1);
	if (parsing(argc, argv) == 1)
		return (1);
	structs = malloc(sizeof(t_Structs));
	rules = malloc(sizeof(t_Rules));
	if (!rules || !structs)
		return (1);
	init_rules_struct(rules, argc, argv);
	pthread_mutex_init(&rules->status_mutex, NULL);
	if (init_fork_lists(&forks, rules) == 1
		|| init_philo_lists(&philos, rules, forks) == 1)
		return (1);
	init_structs(rules, philos, forks, structs);
	thread_init(structs);
	return (free_all(structs), 0);
}
