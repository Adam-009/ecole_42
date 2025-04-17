/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:59:48 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/14 16:16:48 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_COMM_H
# define CHECK_COMM_H

# include "./../main.h"

void	free_everything(char *comm, char **path);
void	error_msg_comm(char *str1, char *str2);
char	*handle_direct_path(char *cmd);
char	*check_full_path(char *path);

#endif