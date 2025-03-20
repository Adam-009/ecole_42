/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:47:31 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/18 07:28:50 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	pa(t_Node **list_a, t_Node **list_b)
{
	t_Node	*temp;

	if (!list_b || !(*list_b))
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	if (*list_b)
		(*list_b)->prev = NULL;
	temp->next = *list_a;
	if (*list_a)
		(*list_a)->prev = temp;
	*list_a = temp;
	ft_printf("pa\n");
}

void	pb(t_Node **list_a, t_Node **list_b)
{
	t_Node	*temp;

	if (!list_a || !(*list_a))
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	if (*list_a)
		(*list_a)->prev = NULL;
	temp->next = *list_b;
	if (*list_b)
		(*list_b)->prev = temp;
	*list_b = temp;
	ft_printf("pb\n");
}
