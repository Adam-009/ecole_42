/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:57:06 by letonnel          #+#    #+#             */
/*   Updated: 2025/10/15 16:57:51 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include "../minishell.h"

void	create_pipes(t_pipe *pipex)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = pipex->head_cmd;
	while (tmp && tmp->next)
	{
		if (pipe(pipex->fd + 2 * i) < 0)
		{
			perror("pipe\n");
			exit(1);
		}
		i++;
		tmp = tmp->next;
	}
}

void	close_pipes(t_pipe *pipex)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = pipex->head_cmd;
	while (tmp)
	{
		close(pipex->fd[i]);
		close(pipex->fd[++i]);
		i++;
		tmp = tmp->next;
	}
}
