/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:37:29 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/18 07:19:14 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	rra(t_Node **list, int v)
{
	int		lv;
	t_Node	*cur;

	if (!list || !list)
		return ;
	cur = *list;
	while (cur->next != NULL)
		cur = cur->next;
	lv = cur->value;
	while (cur->prev != NULL)
	{
		cur->value = cur->prev->value;
		cur = cur->prev;
	}
	cur->value = lv;
	if (v == 0)
		ft_printf("rra\n");
}

void	rrb(t_Node **list_b, int v)
{
	int		lv;
	t_Node	*cur;

	if (!list_b || !list_b)
		return ;
	cur = *list_b;
	while (cur->next != NULL)
		cur = cur->next;
	lv = cur->value;
	while (cur->prev != NULL)
	{
		cur->value = cur->prev->value;
		cur = cur->prev;
	}
	cur->value = lv;
	if (v == 0)
		ft_printf("rrb\n");
}

void	rrr(t_Node **list_a, t_Node **list_b)
{
	rra(list_a, 1);
	rrb(list_b, 1);
	ft_printf("rrr\n");
}
