/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_already_listed.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:47:54 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/03 12:31:59 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	c_onenum(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	if (i == 1)
		return (1);
	return (0);
}

int	c_listed(char **list)
{
	int	i;
	int	c;
	int	size;

	i = 0;
	c = 1;
	size = 0;
	while (list[size])
		size++;
	while (list[i + 1])
	{
		if (ft_atol(list[i]) < ft_atol(list[i + 1]))
			c++;
		i++;
	}
	if (c == size)
		return (1);
	return (0);
}

int	check_ifal(char **list)
{
	if (c_onenum(list) == 1)
		return (1);
	if (c_listed(list) == 1)
		return (1);
	return (0);
}
