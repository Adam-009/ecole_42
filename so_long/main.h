/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:30:07 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/06 12:11:02 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "struct.h"
# include "my_libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>

int		init_value(t_Game *game, char *map);
int		check_map(t_Game *game);
void	load_images(t_Game *game);
void	free_map(char **map);
int		ft_check_file(const char *file);
int		screen(t_Game *wt);
char	**ft_strdup_2d(char **src);
int		find_p(t_Game *game);
void	free_struct(t_Game *game);
int		close_game(t_Game *game);

#endif