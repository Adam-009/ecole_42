/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:26:22 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/09 12:31:42 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if ((nb == 1) || (nb == 0))
	{
		return (1);
	}
	return (nb * ft_recursive_factorial (nb - 1));
}
/*
#include <stdio.h>
int    main(void)
{
    printf("%i\n",ft_recursive_factorial(30));
}*/
