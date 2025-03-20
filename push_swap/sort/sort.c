/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:29:25 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/20 07:50:58 by asaadi--         ###   ########.fr       */
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
	else if (f_szlist(list_a) > 3)
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
		init_sort(*list_a, *list_b, 0);
		cheap_a = f_cheap(*list_a);
		move_a(list_a, list_b, &cheap_a);
	}
	sort_3(list_a);
	while (*list_b)
	{
		init_sort(*list_a, *list_b, 1);
		cheap_b = f_cheap(*list_b);
		move_b(list_b, list_a, &cheap_b);
	}
	croissant(list_a);
}

void	move_a(t_Node **list_a, t_Node **list_b, t_Node **node)
{
	long int	tmp_a;
	long int	tmp_b;

	tmp_a = (*node)->value;
	tmp_b = (*node)->target->value;
	move_together(list_a, list_b, node);
	while ((*list_a)->value != tmp_a)
	{
		if ((*node)->medium == 1)
			ra(list_a, 0);
		else
			rra(list_a, 0);
	}
	while ((*list_b)->value != tmp_b)
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
	long int	tmp_a;
	long int	tmp_b;

	tmp_b = (*node)->value;
	tmp_a = (*node)->target->value;
	move_together(list_b, list_a, node);
	while ((*list_b)->value != tmp_b)
	{
		if ((*node)->medium == 1)
			rb(list_b, 0);
		else
			rrb(list_b, 0);
	}
	while ((*list_a)->value != tmp_a)
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
	else if (a < b && b > c && a > c)
		rra(list_a, 0);
	else if (a > b && b < c && a < c)
		sa(list_a, 0);
	else if (a > b && b < c && a > c)
		ra(list_a, 0);
	else if (a > b && b > c)
	{
		sa(list_a, 0);
		rra(list_a, 0);
	}
}
