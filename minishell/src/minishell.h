/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:55:37 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/22 11:59:05 by asaadi--         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "./commands/commands.h"
# include "./check_comm/check_comm.h"
# include "./openfile/openfile.h"
# include "./parsing/parsing.h"
# include "./tokenizer/tokenizer.h"

/*L = left, R = right, DR = double right, DL = double left*/
typedef enum e_token
{
	TEXT,
	PIPE,
	L_REDIR,
	R_REDIR,
	DL_REDIR,
	DR_REDIR
}	t_token;

typedef struct s_Command
{
	char				*cmd;
	int					infile;
	int					outfile;
	t_token				token;
	struct s_Command	*next;
	struct s_Command	*prev;
}	t_Command;

typedef struct s_Minishell
{
	char		**array;
	char		**envp;
	int			fd[2];
	t_Command	*command;
}	t_Minishell;

void	tokenizer(char *command, t_Minishell *minishell);
int		parsing(char **command);
void	free_array(char **array);
void	free_list_cmd(t_Minishell *minishell);
void	history(char *command);
int		pipex(t_Minishell *minishell, char **env);
void	init_command_list(t_Command **command, char **array);

#endif
