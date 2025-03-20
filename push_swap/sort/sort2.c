/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:39:12 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/20 07:20:05 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	move_together(t_Node **list_a, t_Node **list_b, t_Node **node)
{
	long int		tmp_a;
	long int		tmp_b;

	tmp_a = (*node)->value;
	tmp_b = (*node)->target->value;
	while (((*list_a)->value != tmp_a && (*list_b)->value != tmp_b)
		&& (*node)->medium == (*node)->target->medium)
	{
		if ((*node)->medium == 1)
			rr(list_a, list_b);
		else
			rrr(list_a, list_b);
	}
}

void	croissant(t_Node **list_a)
{
	while (ft_issorted(*list_a) == 0)
	{
		if (f_min_max(*list_a, 0)->medium == 1)
			ra(list_a, 0);
		else
			rra(list_a, 0);
	}
}
