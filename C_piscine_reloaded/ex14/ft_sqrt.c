/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:49:27 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/05 13:22:15 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	result;

	result = 0;
	if (nb == 1)
		return (1);
	while (result < nb)
	{
		if ((result * result) == nb)
			return (result);
		result++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%i\n", ft_sqrt(81));
}*/
