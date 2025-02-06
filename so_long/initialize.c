/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:39:44 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/06 14:24:11 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	find_p(t_Game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->a_map[y])
	{
		x = 0;
		while (game->a_map[y][x])
		{
			if (game->a_map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	find_e(t_Game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->a_map[y])
	{
		x = 0;
		while (game->a_map[y][x])
		{
			if (game->a_map[y][x] == 'E')
			{
				game->exit_status = 1;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	load_images(t_Game *game)
{
	int	w;
	int	h;

	game->w = mlx_xpm_file_to_image(game->mlx, "./texture/wall.xpm", &w, &h);
	game->j = mlx_xpm_file_to_image(game->mlx, "./texture/player.xpm", &w, &h);
	game->c = mlx_xpm_file_to_image(game->mlx, "./texture/coll.xpm", &w, &h);
	game->e = mlx_xpm_file_to_image(game->mlx, "./texture/exit.xpm", &w, &h);
	game->p = mlx_xpm_file_to_image(game->mlx, "./texture/path.xpm", &w, &h);
	if (!game->w || !game->j || !game->c || !game->e || !game->p)
	{
		free_struct(game);
		ft_printf("Error:\nproblem loading textures\n");
		exit (0);
	}
}

int	count_map_size_and_c_coll(t_Game *game)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	game->map_w = ft_strlen(game->a_map[0]);
	while (game->a_map[i])
		i++;
	game->map_h = i;
	i = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			c++;
		i++;
	}
	game->tf_coll = c;
	return (0);
}

int	init_value(t_Game *game, char *map)
{
	game->moves = 1;
	game->f_coll = 0;
	game->map = map;
	game->a_map = ft_split(map, '\n');
	game->prev_tile = '0';
	if (count_map_size_and_c_coll(game) == 1)
		return (1);
	if (find_p(game) == 1)
	{
		ft_printf("Error:\nPlayer not found\n");
		return (1);
	}
	if (game->tf_coll == 0)
	{
		ft_printf("Error:\nCollectible not found\n");
		return (1);
	}
	if (find_e(game) == 1)
	{
		ft_printf("Error:\nExit not found\n");
		return (1);
	}
	return (0);
}
