/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:38:42 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/27 12:59:34 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[v] != '\0')
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
	char src[] = " est la meilleur";
	char dest[] = "la stack";
	printf("%s\n", ft_strcat(dest, src));
*/
