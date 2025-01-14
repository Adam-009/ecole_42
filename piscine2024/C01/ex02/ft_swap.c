/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:23:05 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/20 11:16:53 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	ac;
	int	bc;

	ac = *a;
	bc = *b;
	*a = bc;
	*b = ac;
}
/*
#include <stdio.h>
int	main(void)
{
	int	nb1;
	int	nb2;
	int	*ptr1;
	int	*ptr2;

	nb1 = 10;
	nb2 = 20;
	ptr1 = &nb1;
	ptr2 = &nb2;
	printf("anb1: %i\n", nb1);
	printf("anb2: %i\n", nb2);
	ft_swap(ptr1, ptr2);
	printf("nb1: %i\n", nb1);
	printf("nb2: %i\n", nb2);
	return (0);
}*/
