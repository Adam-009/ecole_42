/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:32:09 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/23 14:51:14 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "./../minishell.h"

void	f_pwd(void);
void	f_env(char **envp);
void	f_echo(char *text, int option);
void	f_exit(int status);
void	f_cd(char *path);

#endif