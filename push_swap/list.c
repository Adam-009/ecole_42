/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:24:23 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/14 07:42:58 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_lists(t_Node **list_a, int v, char **value)
{
	int			i;
	t_Node		*temp;

	i = 0;
	temp = NULL;
	while (value[i])
	{
		temp = createnode(ft_atoll(value[i++]));
		if (!temp)
			exit_program(value, list_a, NULL, v);
		addback(list_a, temp);
	}
}

t_Node	*createnode(long int num)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	if (!newnode)
		return (NULL);
	newnode->value = num;
	newnode->medium = 0;
	newnode->moves_cost = 0;
	newnode->target = NULL;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	addback(t_Node **head, t_Node *newnode)
{
	t_Node	*temp;

	if (!head || !newnode)
		return ;
	if (!*head)
	{
		*head = newnode;
		newnode->prev = NULL;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
}
