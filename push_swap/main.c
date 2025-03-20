/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:56:00 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/20 09:02:23 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	push_swap(char **value, int v)
{
	t_Node	*list_a;
	t_Node	*list_b;

	list_b = NULL;
	list_a = NULL;
	if (check_list(value) == 1)
	{
		write(2, "Error\n", 6);
		exit_program(value, &list_a, &list_b, v);
	}
	if (check_ifal(value) == 1)
		exit_program(value, &list_a, &list_b, v);
	init_lists(&list_a, v, value);
	sort(list_a, list_b);
	exit_program(value, &list_a, &list_b, v);
}

int	main(int argc, char **argv)
{
	char	**value;

	value = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		value = ft_split(argv[1], ' ');
		if (!value || !(*value))
			return (1);
		push_swap(value, 1);
	}
	else if (argc > 2)
		push_swap(&argv[1], 0);
}
