/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:24:02 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/01 15:41:24 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_Philos	*createnode_philo(int philo_index, t_Rules *rules, t_Forks *forks)
{
	t_Philos	*newnode;

	newnode = (t_Philos *)malloc(sizeof(t_Philos));
	if (!newnode)
		return (NULL);
	newnode->philo_index = philo_index;
	newnode->forks = forks;
	newnode->rules = rules;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->last_meal = timestamp();
	newnode->number_of_meal = 0;
	pthread_mutex_init(&newnode->last_meal_mutex, NULL);
	return (newnode);
}

void	addback_philo(t_Philos **head, t_Philos *newnode)
{
	t_Philos	*temp;

	if (!head || !newnode)
		return ;
	if (!*head)
	{
		*head = newnode;
		newnode->prev = newnode;
		newnode->next = newnode;
		return ;
	}
	temp = (*head)->prev;
	temp->next = newnode;
	newnode->prev = temp;
	newnode->next = *head;
	(*head)->prev = newnode;
}

int	init_philo_lists(t_Philos **philos, t_Rules *rules, t_Forks *forks)
{
	int			i;
	t_Philos	*temp;

	i = 0;
	while (i < rules->number_of_philo)
	{
		temp = createnode_philo(i + 1, rules, forks);
		if (!temp)
			return (1);
		addback_philo(philos, temp);
		i++;
	}
	return (0);
}
