/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:30 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/18 07:19:01 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ra(t_Node **list_a, int v)
{
	t_Node	*cur;
	int		fv;

	if (!list_a || !list_a)
		return ;
	fv = (*list_a)->value;
	cur = *list_a;
	while (cur->next != NULL)
	{
		cur->value = cur->next->value;
		cur = cur->next;
	}
	cur->value = fv;
	if (v == 0)
		ft_printf("ra\n");
}

void	rb(t_Node **list_b, int v)
{
	t_Node	*cur;
	int		fv;

	if (!list_b || !list_b)
		return ;
	fv = (*list_b)->value;
	cur = *list_b;
	while (cur->next != NULL)
	{
		cur->value = cur->next->value;
		cur = cur->next;
	}
	cur->value = fv;
	if (v == 0)
		ft_printf("rb\n");
}

void	rr(t_Node **list_a, t_Node **list_b)
{
	ra(list_a, 1);
	rb(list_b, 1);
	ft_printf("rr\n");
}
