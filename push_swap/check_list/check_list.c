/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:21:18 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/03 12:32:08 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	invalide_caracter(char **list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if (!(ft_isdigit(list[i][j])) && !(list[i][j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	c_double(char **list)
{
	int	i;
	int	j;

	j = 0;
	while (list[j])
	{
		i = j + 1;
		while (list[i])
		{
			if (ft_strcmp(list[i], list[j]) == 0)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	c_maxint(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (ft_atoll(list[i]) > INT_MAX || ft_atoll(list[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_list(char **list)
{
	if (invalide_caracter(list) == 1)
		return (1);
	if (c_double(list) == 1)
		return (1);
	if (c_maxint(list) == 1)
		return (1);
	return (0);
}
