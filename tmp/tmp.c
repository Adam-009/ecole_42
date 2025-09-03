/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:49:40 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/03 16:30:20 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char *text)
{
	size_t	i;
	
	i = 0;
	if (!text || !text[0])
		return (0);
	while (text[i])
		i++;
	return (i);
}

char	*censcored(char *text, char *to_cens)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	i = 0;
	j = 0;
	if (!to_cens || !text)
		return (NULL);
	while (text[i])
	{
		j = 0;
		k = i;
		while (text[k] == to_cens[j])
		{
			if (j + 1 == ft_strlen(to_cens))
			{
				j = 0;
				while (j != ft_strlen(to_cens))
				{
					text[k] = '*';
					k--;
					j++;
				}
			}
			k++;
			j++;
		}
		i++;
	}
	return (text);
}

char	*ft_join(char c, char *text)
{
	unsigned long	i;
	char *str;
	
	i = 0;
	if (!c)
		return (NULL);
	if (!text)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = c;
		return (str);
	}
	str = malloc(sizeof(char) * (ft_strlen(text) + 2));
	while(text[i])
	{
		str[i] = text[i];
		i++;
	}
	str[i] = c;
	str[++i] = '\0';
	free(text);
	return (str);
}

int	main(int argc, char **argv)
{
	char	*to_cens;
	char	c;
	char	*text;
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	text = NULL;
	if (argc != 2)
		return (printf("nombre d'arg invalide\n"), 1);
	to_cens = argv[1];
	while (read(STDIN_FILENO, &c, 1) != 0)
	{
		if (c == '\n')
			break ;
		text = ft_join(c, text);
	}
	result = censcored(text, to_cens);
		if (!result)
			return (printf("error\n"), 1);
	printf("%s", result);
	return (0);
}