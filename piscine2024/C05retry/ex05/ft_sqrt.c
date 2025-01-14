/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:36:12 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/10 17:51:27 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (nb < 0)
		return (0);
	while (result < nb && i <= 46340)
	{
		result = i * i;
		if (result == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int    main(void)
{
    int    nb;

    nb = 2147302921;
    printf("Test : %d\n", ft_sqrt(nb));
    return (0);
}*/