/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:18:50 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/01 10:54:09 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char s1[] = "Toto";
	char s2[] = "Tot";
	int i;
	printf("chaine de caractere s1: %s\nchaine de caratere s2: %s\n", s1, s2);
	i = ft_strcmp(s1, s2);
	printf("%d\n", i);
}*/
