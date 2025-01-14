/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:40:01 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/24 18:05:37 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] <= 'z' && str[i] >= 'a')
				|| (str[i] <= 'Z' && str[i] >= 'A')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	char text[] = "00dam";
	int i;
	i = ft_str_is_alpha(text);
	printf("%d\n", i);
	return(0);
}*/
