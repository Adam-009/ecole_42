/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:07:58 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/10 17:53:21 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	resultat;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	resultat = 1;
	while (nb != 0)
	{
		resultat *= nb;
		--nb;
	}
	return (resultat);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	printf("%i\n", ft_iterative_factorial(INT_MAX));
}*/
