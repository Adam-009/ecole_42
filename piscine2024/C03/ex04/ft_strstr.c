/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:16:56 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/01 10:52:11 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	x;
	int	v;

	i = 0;
	if (!to_find[0])
		return (str);
	while (str[i] != '\0')
	{
		x = 0;
		if (str[i] == to_find[x])
		{
			v = i;
			while (str[v] == to_find[x] && str[v] != '\0')
			{
				v++;
				x++;
			}
		}
		if (to_find[x] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
        char str[] = "la stack est la meilleur des coalitions";
        char to_find[] = "coalitions";
        printf("%s\n", ft_strstr(str, to_find));
        printf("%s\n", strstr(str, to_find));

}
*/
