/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:33:15 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/10 17:52:32 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power >= 1)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
/*
int    main(void)
{
    printf("result du test %d\n", ft_iterative_power(10, 10));
    return (0);
}
*/