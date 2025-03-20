/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:45:30 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/20 07:31:47 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_sort(t_Node *list_a, t_Node *list_b, int v)
{
	if (v == 0)
	{
		f_medium(list_a);
		f_medium(list_b);
		f_targets(list_a, list_b);
		f_cost(list_a, list_b, 0);
	}
	if (v == 1)
	{
		f_medium(list_b);
		f_medium(list_a);
		f_revtargets(list_b, list_a);
		f_cost(list_a, list_b, 1);
	}
}

void	f_targets(t_Node *shooters, t_Node *suspects)
{
	t_Node	*target;
	t_Node	*current_suspect;

	while (shooters)
	{
		target = NULL;
		current_suspect = suspects;
		if (shooters->value < f_min_max(suspects, 0)->value)
			shooters->target = f_min_max(suspects, 1);
		else
		{
			while (current_suspect)
			{
				if (current_suspect->value < shooters->value)
					if (!target || current_suspect->value > target->value)
						target = current_suspect;
				current_suspect = current_suspect->next;
			}
			if (target)
				shooters->target = target;
			else
				shooters->target = f_min_max(suspects, 0);
		}
		shooters = shooters->next;
	}
}

void	f_medium(t_Node *list)
{
	int		middle;
	int		i;
	t_Node	*current;

	middle = f_szlist(list) / 2;
	i = 1;
	current = list;
	while (current)
	{
		if (i > middle)
			current->medium = 2;
		else
			current->medium = 1;
		i++;
		current = current->next;
	}
}

int	f_cost2(t_Node *list, t_Node *node)
{
	int	cost;

	cost = 0;
	if (node == list->next)
		return (1);
	if (node->medium == 1)
	{
		while (node != list)
		{
			cost++;
			list = list->next;
		}
	}
	else if (node->medium == 2)
	{
		while (list->next)
			list = list->next;
		while (node != list)
		{
			cost++;
			list = list->prev;
		}
		cost++;
	}
	return (cost);
}

void	f_cost(t_Node *list_a, t_Node *list_b, int v)
{
	t_Node	*tmp;
	int		cost;

	if (v == 0)
	{
		tmp = list_a;
		while (list_a)
		{
			cost = f_cost2(tmp, list_a) + f_cost2(list_b, list_a->target);
			list_a->moves_cost = cost;
			list_a = list_a->next;
		}
	}
	else if (v == 1)
	{
		tmp = list_b;
		while (list_b)
		{
			cost = f_cost2(tmp, list_b) + f_cost2(list_a, list_b->target);
			list_b->moves_cost = cost;
			list_b = list_b->next;
		}
	}
}
