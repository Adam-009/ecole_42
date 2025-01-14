/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:14:20 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/04 14:37:20 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	p1;
	int	p2;

	p1 = *a;
	p2 = *b;
	*a = p2;
	*b = p1;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	printf("a est egale a: %i\n", a);
	printf("b est egale a: %i\n", b);
	ft_swap(&a, &b);
	printf("modif\na est egale a: %i", a);
	printf("\nb est egale a: %i\n", b);
}*/
