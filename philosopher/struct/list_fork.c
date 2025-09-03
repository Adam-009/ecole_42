/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:48:38 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/01 18:53:56 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../main.h"

t_Forks	*createnode_fork(int fork_index)
{
	t_Forks	*newnode;

	newnode = (t_Forks *)malloc(sizeof(t_Forks));
	if (!newnode)
		return (NULL);
	newnode->fork_index = fork_index;
	newnode->mutex = malloc(sizeof(pthread_mutex_t));
	if (!newnode->mutex)
		return (NULL);
	if (pthread_mutex_init(newnode->mutex, NULL) != 0)
		return (NULL);
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	addback_fork(t_Forks **head, t_Forks *newnode)
{
	t_Forks	*temp;

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

int	init_fork_lists(t_Forks **fork, t_Rules *rules)
{
	int			i;
	t_Forks		*temp;

	i = 0;
	while (i < rules->number_of_philo)
	{
		temp = createnode_fork(i + 1);
		if (!temp)
			return (1);
		addback_fork(fork, temp);
		i++;
	}
	return (0);
}
