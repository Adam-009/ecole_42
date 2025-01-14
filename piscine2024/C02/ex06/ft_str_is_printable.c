/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:32:59 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/25 18:49:19 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > 31 && str[i] < 127) || (str[i] == '\0'))
			i++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	char text[] = " ";
	printf("%d\n", ft_str_is_printable(text));
	return(0);
}*/
