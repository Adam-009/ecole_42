/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:50:23 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/25 13:49:40 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**find_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = ft_split(&env[i][5], ':');
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*isole_command(char *command)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!command)
		return (NULL);
	while (command[i] && command[i] != ' ')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (command[i] && command[i] != ' ')
		tmp[j++] = command[i++];
	tmp[j] = '\0';
	return (tmp);
}
