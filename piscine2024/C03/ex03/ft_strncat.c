/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:44:19 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/30 17:00:48 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	v;

	i = 0;
	v = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[v] != '\0' && v < nb)
	{
		dest[i] = src[v];
		i++;
		v++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = " est la meilleur !";
	char dest[] = "la stack";
	int nb = 4;
	printf("%s", ft_strncat(dest, src, nb));
}*/
