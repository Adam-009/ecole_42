/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:47:31 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/04 11:33:39 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./my_libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_Struct
{
	char	*file1;
	char	*file2;
	int		argc;
	char	**argv;
	char	**envp;
	int		fd1;
	int		fd2;
	int		pipefd[2];
	char	*pathtocmd1;
	char	*pathtocmd2;
	int		exit_status;
	char	*exit_msg;
	int		msg_status;
}	t_Struct;

void	error(t_Struct *str, int exit_status, char *exit_msg, int msg_status);
void	exit_program(t_Struct *str);
void	check_args(char **commands, int size, char **env, t_Struct *str);
char	*isole_command(char *command);
char	**find_path(char **env);
void	free_array(char **array);
void	c_if_command_exist(char **comm, char **env, int size, t_Struct *str);

#endif