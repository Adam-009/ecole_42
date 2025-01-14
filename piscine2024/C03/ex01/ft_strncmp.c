/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:28:52 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/27 12:52:19 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i] && i < n)
		return (s1[i] - s2[i]);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char s1[5] = "Toto";
	char s2[5] = "Tot";
	int n = 5;
	int i;
	printf("chaine de caractere de s1: %s\nchaine de caratere de s2: %s\n", s1, s2);
	i = ft_strncmp(s1, s2, n);
	printf("%i", i);
	return (0);
}*/
