/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:55:37 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/29 13:59:49 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <termcap.h>
# include <readline/readline.h> 
# include <readline/history.h>
# include <sys/ioctl.h>

# include "./libft/libft.h"
# include "./commands/commands.h"
# include "./check_comm/check_comm.h"
# include "./openfile/openfile.h"

typedef struct s_Minishell
{
	char	**envp;
	char	**command;
}	t_Minishell;

void	free_array(char **array);
void	find_command(t_Minishell *minishell, int index);

#endif