/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:02:49 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/14 11:32:35 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	f_szlist(t_Node *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_Node	*f_last_node(t_Node *list)
{
	t_Node	*tmp;

	tmp = list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	return (tmp);
}

t_Node	*f_min_max(t_Node *list, int v)
{
	t_Node	*num;

	if (!list)
		return (NULL);
	num = list;
	while (list)
	{
		if (v == 0 && num->value > list->value)
			num = list;
		if (v == 1 && num->value < list->value)
			num = list;
		list = list->next;
	}
	return (num);
}

t_Node	*f_cheap(t_Node *list)
{
	t_Node	*cheapest;

	cheapest = list;
	while (list)
	{
		if (cheapest->moves_cost > list->moves_cost)
			cheapest = list;
		list = list->next;
	}
	return (cheapest);
}
