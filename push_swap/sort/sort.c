/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:29:25 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/18 09:55:27 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	tuckish_sort(t_Node **list_a, t_Node **list_b);
void	move_a(t_Node **list_a, t_Node **list_b, t_Node **node);
void	move_b(t_Node **list_b, t_Node **list_a, t_Node **node);
void	sort_3(t_Node **list_a);

void	sort(t_Node *list_a, t_Node *list_b)
{
	if (f_szlist(list_a) == 2)
		sa(&list_a, 0);
	else if (f_szlist(list_a) == 3)
		sort_3(&list_a);
	else
		tuckish_sort(&list_a, &list_b);
}

void	tuckish_sort(t_Node **list_a, t_Node **list_b)
{
	t_Node	*cheap_a;
	t_Node	*cheap_b;

	if (f_szlist(*list_a) > 3)
		pb(list_a, list_b);
	if (f_szlist(*list_a) > 3)
		pb(list_a, list_b);
	while (f_szlist(*list_a) > 3)
	{
		cheap_a = f_cheap(*list_a);
		init_sort(*list_a, *list_b, 0);
		move_a(list_a, list_b, &cheap_a);
	}
	sort_3(list_a);
	while (*list_b)
	{
		cheap_b = f_cheap(*list_b);
		init_sort(*list_a, *list_b, 1);
		move_b(list_b, list_a, &cheap_b);
	}
	while (ft_issorted(*list_a) == 0)
		ra(list_a, 0);
}

void	move_a(t_Node **list_a, t_Node **list_b, t_Node **node)
{
	int		tmp;

	while (*list_a != *node)
	{
		if ((*node)->medium == 1)
			ra(list_a, 0);
		else
			rra(list_a, 0);
	}
	tmp = (*node)->target->value;
	while ((*list_b)->value != tmp)
	{
		if ((*node)->target->medium == 1)
			rb(list_b, 0);
		else
			rrb(list_b, 0);
	}
	pb(list_a, list_b);
}

void	move_b(t_Node **list_b, t_Node **list_a, t_Node **node)
{
	int		tmp;

	tmp = (*node)->value;
	while ((*list_b)->value != tmp)
	{
		if ((*node)->medium == 1)
			rb(list_b, 0);
		else
			rrb(list_b, 0);
	}
	tmp = (*node)->target->value;
	while ((*list_a)->value != tmp)
	{
		if ((*node)->target->medium == 1)
			ra(list_a, 0);
		else
			rra(list_a, 0);
	}
	pa(list_a, list_b);
}

void	sort_3(t_Node **list_a)
{
	int	a;
	int	b;
	int	c;

	a = (*list_a)->value;
	b = (*list_a)->next->value;
	c = (*list_a)->next->next->value;
	if (a < b && b > c && a < c)
	{
		sa(list_a, 0);
		ra(list_a, 0);
	}
	else if (a > b && b < c && a < c)
		sa(list_a, 0);
	else if (a < b && b > c)
		rra(list_a, 0);
	else if (a > b && b < c && a > c)
		ra(list_a, 0);
	else if (a > b && b > c)
	{
		sa(list_a, 0);
		rra(list_a, 0);
	}
}
