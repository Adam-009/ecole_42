/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:18:19 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/20 11:19:39 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int	main(void)
{
	int a;
	a = 50;
	int b;
	b = 5;
	int *ptr;
	int *ptdr;
        
	ptr = &a;
	ptdr = &b;
	ft_div_mod(a, b, ptr, ptdr);
	printf("a diviser par b: %i\n", *ptr);
	printf("a diviser par b: %i\n", *ptdr);
	return (0);
}*/
