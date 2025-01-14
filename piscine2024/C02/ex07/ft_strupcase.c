/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:18:27 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/24 18:09:31 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 122 && str[i] >= 97)
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char	str[] = "test";
	int	 i;
	i = 0;
	ft_strupcase(str);
	while(str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
}*/
