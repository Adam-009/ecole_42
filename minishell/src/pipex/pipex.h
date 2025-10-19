/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:50:47 by letonnel          #+#    #+#             */
/*   Updated: 2025/10/07 17:19:33 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include "../minishell.h"

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_pipe
{
	char		**split_path;
	char		**cmd;
	int			in;
	int			out;
	int			i;
	int			exit;
	int			cmds;
	int			*fd;
	pid_t		*pid;
	int			found;
	int			here;
	t_cmd		*head_cmd;
}	t_pipe;

void		free_split(char **tab);
char		*find_path_cmd(char **env);
void		close_pipes(t_pipe *pipex);
void		create_pipes(t_pipe *pipex);
void		end_pip(t_pipe *pipex);
char		*get_cmd_path(char *cmd, char **env, t_pipe *pip);
void		init_pipe(int ac, t_pipe *pipex);
int			get_exit_status(t_pipe pipex);
void		print_error(int code, char *arg);
char		**parse_line(int *ac, char *line, t_pipe *pip);
int			token_check(t_Minishell *minishell);
void		addback_pipex(t_cmd **head, t_cmd *newnode);
t_cmd		*createnode_pipex(char *array);
void		free_cmd_list(t_cmd *head);
void		pre_exec(t_Command *cmd, t_pipe *pipex);
void		start_exec(t_pipe *pipex, char **env, t_Minishell *minishell);
void		proc(char *cmd, char **env, t_pipe pip);

#endif
