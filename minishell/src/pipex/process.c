/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:47:16 by letonnel          #+#    #+#             */
/*   Updated: 2025/10/10 15:47:18 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include "../minishell.h"

char	*ft_join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = -1;
	j = 0;
	if (result == NULL)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

void	pre_exec(t_Command *cmd, t_pipe *pipex)
{
	t_cmd	*head;
	char	*line;
	t_cmd	*node;

	head = NULL;
	while (cmd)
	{
		if (cmd->token == TEXT)
		{
			line = ft_strdup(cmd->cmd);
			while (cmd->next && cmd->next->token == TEXT)
			{
				line = ft_join(line, " ");
				line = ft_join(line, cmd->next->cmd);
				cmd = cmd->next;
			}
			node = createnode_pipex(line);
			free(line);
			addback_pipex(&head, node);
		}
		cmd = cmd->next;
	}
	pipex->head_cmd = head;
}

void	child_process(t_pipe *pip, char **env, t_cmd *cmd, t_Minishell *mini)
{
	if (pip->i == 0 && cmd->next)
		dup2(pip->fd[2 * pip->i + 1], STDOUT_FILENO);
	else if (pip->i > 0 && cmd->next)
	{
		dup2(pip->fd[2 * pip->i - 2], STDIN_FILENO);
		dup2(pip->fd[2 * pip->i + 1], STDOUT_FILENO);
	}
	else if (pip->i > 0 && !cmd->next)
		dup2(pip->fd[2 * pip->i - 2], STDIN_FILENO);
	close(mini->fd[0]);
	close(mini->fd[1]);
	close_pipes(pip);
	proc(cmd->cmd, env, *pip);
}

void	parent_process(t_pipe *pip, char **env, t_cmd *cmd, t_Minishell *mini)
{
	pip->pid[pip->i] = fork();
	if (pip->pid[pip->i] == 0)
		child_process(pip, env, cmd, mini);
}

void	start_exec(t_pipe *pipex, char **env, t_Minishell *minishell)
{
	t_cmd	*tmp;

	pipex->i = 0;
	tmp = pipex->head_cmd;
	while (tmp)
	{
		pipex->head_cmd = tmp;
		parent_process(pipex, env, tmp, minishell);
		tmp = tmp->next;
		pipex->i++;
	}
}
