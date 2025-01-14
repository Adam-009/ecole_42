/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:01:50 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/08 12:47:17 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 0;
	if (nb >= 13)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	if (nb > 1)
		result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}
/*
int	main(void)
{
	printf("%i\n", ft_recursive_factorial(0));
}*/
