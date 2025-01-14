/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:00:26 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/29 20:10:30 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

char	ft_print2(char *ligne)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i != 4)
	{
		write (1, &ligne[i], 1);
		if (c < 3)
		{
			write (1, " ", 1);
			c++;
		}
		i++;
	}
	return (0);
}

char	ft_print(char *chaine)
{
	int	v;
	int	c;

	c = 0;
	v = 0;
	while (v < 16)
	{
		ft_print2(&chaine[v]);
		if (c < 3)
		{
			write (1, "\n", 1);
			c++;
		}
		v += 4;
	}
	return (0);
}
