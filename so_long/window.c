/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:02:03 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/06 12:10:45 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display_map(t_Game *game, int ts, int y);

void	move_player(t_Game *g, int new_y, int new_x)
{
	if (g->a_map[new_y][new_x] == 'C')
		g->f_coll++;
	if (g->f_coll == g->tf_coll)
		g->exit_status = 0;
	if (g->a_map[new_y][new_x] == 'E' && g->exit_status == 0)
	{
		ft_printf("You win!\n");
		free_struct(g);
		exit(0);
	}
	if (g->a_map[new_y][new_x] != '1')
	{
		ft_printf("moves: %i\n", g->moves++);
		if (g->a_map[g->y][g->x] == 'P')
		{
			if (g->prev_tile == 'E')
				g->a_map[g->y][g->x] = 'E';
			else
				g->a_map[g->y][g->x] = '0';
		}
		g->prev_tile = g->a_map[new_y][new_x];
		g->y = new_y;
		g->x = new_x;
		g->a_map[g->y][g->x] = 'P';
	}
}

void	moves(t_Game *g, char c)
{
	if (c == 'w' && g->y > 0)
		move_player(g, g->y - 1, g->x);
	if (c == 's' && g->y < g->map_h - 1)
		move_player(g, g->y + 1, g->x);
	if (c == 'a' && g->x > 0)
		move_player(g, g->y, g->x - 1);
	if (c == 'd' && g->x < g->map_w - 1)
		move_player(g, g->y, g->x + 1);
}

int	key_hook(int keycode, t_Game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119)
		moves(game, 'w');
	if (keycode == 97)
		moves(game, 'a');
	if (keycode == 115)
		moves(game, 's');
	if (keycode == 100)
		moves(game, 'd');
	mlx_clear_window(game->mlx, game->mw);
	display_map(game, 32, -1);
	return (0);
}

void	display_map(t_Game *game, int ts, int y)
{
	int	x;

	while (game->a_map[++y])
	{
		x = -1;
		while (game->a_map[y][++x])
		{
			if (game->a_map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mw, game->w,
					x * ts, y * ts);
			else if (game->a_map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mw, game->j,
					x * ts, y * ts);
			else if (game->a_map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mw, game->c,
					x * ts, y * ts);
			else if (game->a_map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mw, game->e,
					x * ts, y * ts);
			else if (game->a_map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->mw, game->p,
					x * ts, y * ts);
		}
	}
}

int	screen(t_Game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->mw = mlx_new_window(game->mlx, (32 * game->map_w),
			(32 * game->map_h), "so long");
	if (!game->mw)
	{
		free_map(game->a_map);
		return (1);
	}
	load_images(game);
	display_map(game, 32, -1);
	mlx_key_hook(game->mw, key_hook, game);
	mlx_hook(game->mw, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
