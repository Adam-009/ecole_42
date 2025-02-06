/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:05:55 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/06 14:13:53 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	c_caractere(t_Game *game)
{
	int		i;
	int		e;
	int		p;
	char	*str;

	e = 0;
	p = 0;
	i = 0;
	str = game->map;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'E'
			&& str[i] != 'P' && str[i] != 'C' && str[i] != '\n')
			return (1);
		if (str[i] == 'E')
			e++;
		if (str[i] == 'P')
			p++;
		i++;
	}
	if (e != 1 || p != 1)
		return (1);
	return (0);
}

int	c_border_map(t_Game *game)
{
	int		j;
	int		i;
	size_t	map_size;

	map_size = ft_strlen(game->a_map[0]);
	j = -1;
	i = -1;
	while (game->a_map[0][++j])
		if (game->a_map[0][j] != '1')
			return (1);
	while (game->a_map[++i + 1])
	{
		if (game->a_map[i][0] != '1' ||
		game->a_map[i][ft_strlen(game->a_map[i]) - 1] != '1' ||
			ft_strlen(game->a_map[i]) != map_size)
			return (1);
	}
	j = -1;
	while (game->a_map[i][++j])
		if (game->a_map[i][j] != '1' || ft_strlen(game->a_map[i]) != map_size)
			return (1);
	return (0);
}

int	path(char **map, int x, int y, int *count)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return (0);
	if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P')
		(*count)++;
	map[y][x] = '2';
	path(map, x, y - 1, count);
	path(map, x + 1, y, count);
	path(map, x, y + 1, count);
	path(map, x - 1, y, count);
	return (1);
}

int	flood_fill(t_Game *game)
{
	int		count;
	char	**temp;

	temp = ft_strdup_2d(game->a_map);
	if (!temp)
		return (1);
	count = 0;
	path(temp, game->x, game->y, &count);
	free_map(temp);
	if (count == (game->tf_coll + 2))
		return (0);
	return (1);
}

int	check_map(t_Game *game)
{
	if (c_caractere(game) == 1)
	{
		ft_printf("Error:\nInvalide caractere\n");
		return (1);
	}
	if (c_border_map(game) == 1)
	{
		ft_printf("Error:\nBorder map invalid\n");
		return (1);
	}
	if (flood_fill(game) == 1)
	{
		ft_printf("Error:\nInvalide path\n");
		return (1);
	}
	return (0);
}
