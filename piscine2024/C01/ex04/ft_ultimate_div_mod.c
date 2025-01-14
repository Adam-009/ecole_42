/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:51:04 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/20 11:22:29 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	rdiv;
	int	rmod;

	rdiv = *a / *b;
	rmod = *a % *b;
	*a = rdiv;
	*b = rmod;
}
/*
#include <stdio.h>
int	main(void)
{
	int	nbr1;
	int	nbr2;
	int	*ptr1;
	int	*ptr2;

	nbr1 = 50;
	nbr2 = 5;
	ptr1 = &nbr1;
	ptr2 = &nbr2;
	printf("nbr1: %i\n", nbr1);
	printf("nbr2: %i\n", nbr2);
	ft_ultimate_div_mod(ptr1, ptr2);
	printf("div: %i\n", nbr1);
	printf("mod: %i\n", nbr2);
	return (0);
}*/
