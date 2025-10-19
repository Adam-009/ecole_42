/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:50:56 by letonnel          #+#    #+#             */
/*   Updated: 2025/10/07 18:35:39 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include "../minishell.h"

int	cmd_count(t_Minishell *minishell)
{
	t_Command	*tmp;
	int			count;

	tmp = minishell->command;
	count = 1;
	while (tmp)
	{
		if (tmp->token == PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	proc(char *cmd, char **env, t_pipe pip)
{
	char	*path_cmd;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	pip.found = 0;
	path_cmd = get_cmd_path(cmd, env, &pip);
	execve(cmd, cmd_arg, env);
	if (execve(path_cmd, cmd_arg, env) == -1)
	{
		if (cmd_arg[0])
		{
			if (pip.found && access(path_cmd, X_OK) == -1)
			{
				print_error(1, cmd_arg[0]);
				return (free_split(cmd_arg), close_pipes(&pip),
					end_pip(&pip), free(path_cmd), exit(126));
			}
			free(path_cmd);
		}
		print_error(2, cmd_arg[0]);
		return (free_split(cmd_arg), close_pipes(&pip),
			end_pip(&pip), exit(127));
	}
}

int	pipex(t_Minishell *minishell, char **env)
{
	t_pipe	pipex;

	if (token_check(minishell) == 1)
		return (1);
	pipex.in = 0;
	pipex.out = 1;
	pipex.cmds = cmd_count(minishell);
	init_pipe(pipex.cmds, &pipex);
	pre_exec(minishell->command, &pipex);
	create_pipes(&pipex);
	start_exec(&pipex, env, minishell);
	close_pipes(&pipex);
	pipex.exit = get_exit_status(pipex);
	end_pip(&pipex);
	free_cmd_list(pipex.head_cmd);
	return (pipex.exit);
}
