/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:17:42 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/25 17:10:38 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 90 && str[i] >= 65)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
        char    str[] = "TEST";
        int      i;
        i = 0;
        ft_strlowcase(str);
        while(str[i] != '\0')
        {
                printf("%c", str[i]);
                i++;
        }
        return (0);
}*/
