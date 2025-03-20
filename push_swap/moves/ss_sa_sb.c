/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_sa_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:05:12 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/18 07:13:52 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	sa(t_Node **list_a, int v)
{
	t_Node	*temp;

	if ((*list_a) == NULL || (*list_a) == NULL || (*list_a)->next == NULL)
		return ;
	temp = (t_Node *)malloc(sizeof(t_Node));
	if (temp == NULL)
		return ;
	temp->value = (*list_a)->value;
	(*list_a)->value = (*list_a)->next->value;
	(*list_a)->next->value = temp->value;
	if (v == 0)
		ft_printf("sa\n");
	free(temp);
}

void	sb(t_Node **list_b, int v)
{
	t_Node	*temp;

	if ((*list_b) == NULL || (*list_b) == NULL || (*list_b)->next == NULL)
		return ;
	temp = (t_Node *)malloc(sizeof(t_Node));
	if (temp == NULL)
		return ;
	temp->value = (*list_b)->value;
	(*list_b)->value = (*list_b)->next->value;
	(*list_b)->next->value = temp->value;
	if (v == 0)
		ft_printf("sb\n");
	free(temp);
}

void	ss(t_Node **list_a, t_Node **list_b)
{
	sa(list_a, 1);
	sb(list_b, 1);
	ft_printf("ss\n");
}
