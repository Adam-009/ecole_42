/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:56:23 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/24 18:12:20 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && alphanum(str[i - 1]) == 0)
			str[i] = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && alphanum(str[i - 1]) == 1)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "SALUTT, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	int	i;
	i = 0;
	ft_strcapitalize(str);
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
}*/
