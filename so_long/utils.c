/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:44:51 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/06 12:10:53 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_check_file(const char *file)
{
	const char	*ext;
	int			file_len;
	int			ext_len;

	ext = ".ber";
	file_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (file_len < ext_len)
		return (1);
	while (ext_len > 0)
	{
		if (file[file_len - 1] != ext[ext_len - 1])
			return (1);
		file_len--;
		ext_len--;
	}
	return (0);
}

char	**ft_strdup_2d(char **src)
{
	char	**copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_struct(t_Game *game)
{
	if (game->w)
		mlx_destroy_image(game->mlx, game->w);
	if (game->j)
		mlx_destroy_image(game->mlx, game->j);
	if (game->c)
		mlx_destroy_image(game->mlx, game->c);
	if (game->e)
		mlx_destroy_image(game->mlx, game->e);
	if (game->p)
		mlx_destroy_image(game->mlx, game->p);
	if (game->mw)
		mlx_destroy_window(game->mlx, game->mw);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->a_map);
	free(game->map);
}

int	close_game(t_Game *game)
{
	free_struct(game);
	exit(0);
	return (0);
}
