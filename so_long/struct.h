/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:31:13 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/06 11:27:47 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_Game
{
	int		x;
	int		y;
	int		f_coll;
	int		tf_coll;
	int		exit_status;
	char	*map;
	char	**a_map;
	int		map_w;
	int		map_h;
	void	*mlx;
	void	*mw;
	void	*e;
	void	*j;
	void	*c;
	void	*p;
	void	*w;
	int		moves;
	char	prev_tile;
}	t_Game;

#endif