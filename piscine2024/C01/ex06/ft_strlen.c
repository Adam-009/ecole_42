/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:55:53 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/20 14:14:22 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main(void)
{
	int c;
	char *ptr;
	ptr = "abcdefghijklmnopqrstuvwxyz";
	c = ft_strlen(ptr);
	printf("le nombre de caracteres est: %d\n", c);
	return (0);
}*/
