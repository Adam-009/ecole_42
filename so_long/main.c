/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:28:48 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/06 14:30:07 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	so_long(char *temp)
{
	t_Game	game;

	if ((init_value(&game, temp) == 1)
		|| (check_map(&game) == 1))
	{
		free_map(game.a_map);
		free(game.map);
		return (1);
	}
	screen(&game);
	free_map(game.a_map);
	free_struct(&game);
	return (0);
}

int	verif_file(int argc, char *argv)
{
	if (argc < 2 || ft_check_file(&argv[1]) == 1)
	{
		ft_printf("Error:\nMissing or incorrect file argument.\n");
		return (1);
	}
	return (0);
}

char	*read_map(int fd, char *map)
{
	char	*temp;
	char	*tmp_map;

	temp = get_next_line(fd);
	while (temp)
	{
		if (!map)
			map = ft_strdup(temp);
		else
		{
			tmp_map = ft_strjoin(map, temp);
			if (!tmp_map)
			{
				free(map);
				free(temp);
				return (NULL);
			}
			free(map);
			map = tmp_map;
		}
		free(temp);
		temp = get_next_line(fd);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*map;

	if (argc != 2)
		return (1);
	if (verif_file(argc, argv[1]) == 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error:\nCannot read file.\n"), 1);
	map = read_map(fd, NULL);
	close(fd);
	if (!map)
		return (ft_printf("Error:\nEmpty map.\n"), 1);
	so_long(map);
}
