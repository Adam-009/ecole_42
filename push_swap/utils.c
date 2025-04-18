/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:05:45 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/20 09:13:22 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_list(t_Node *list)
{
	t_Node	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	free_value(char **value)
{
	int		i;

	i = 0;
	while (value[i])
		free(value[i++]);
	free(value);
}

void	exit_program(char **value, t_Node **list_a, t_Node **list_b, int v)
{
	if (v == 1 && value)
		free_value(value);
	if (*list_a)
	{
		free_list(*list_a);
		*list_a = NULL;
	}
	if (*list_b)
	{
		free_list(*list_b);
		*list_b = NULL;
	}
	exit(1);
}

int	ft_issorted(t_Node *list)
{
	while (list && list->next)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}
