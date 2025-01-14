/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:49:11 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/06 11:11:33 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	resultat;

	if (nb < 0)
		return (0);
	if (nb >= 13)
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
