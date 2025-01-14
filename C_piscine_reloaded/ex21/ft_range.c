/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:56:51 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/06 14:53:11 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	number;
	int	*array;

	number = min;
	i = 0;
	array = NULL;
	if (min < max)
	{
		i = max - min;
		array = malloc(sizeof(int) * i);
		if (array == NULL)
			return (array);
		i = 0;
		while (number != max)
		{
			array[i] = number;
			i++;
			number++;
		}
		i = 0;
		return (&array[i++]);
	}
	return (array);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	i;
	int	*array;

	i = 0;
	min = 10;
	max = 25;
	array = ft_range(min, max);
	while (i < (max - min))
	{
		printf("%i\n", array[i++]);
	}
}*/
