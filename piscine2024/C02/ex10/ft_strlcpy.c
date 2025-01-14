/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:24 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/05 13:09:07 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size);
}

#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
	char    src[5] = "tuest";
	char    dest[5];
	int	size = '5';

	printf("%i\n", ft_strlcpy(dest, src, size));
	printf("%zu\n", strlcpy(dest, src, size));
	printf("src : %s\n", src);
	printf("dest : %s\n", dest);
}
