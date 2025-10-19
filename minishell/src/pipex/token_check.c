/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letonnel <letonnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:08:33 by letonnel          #+#    #+#             */
/*   Updated: 2025/09/30 17:07:08 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include "../minishell.h"

int	pipe_check(t_Minishell *minishell)
{
	t_Command	*tmp;

	tmp = minishell->command;
	if (!tmp)
		return (-1);
	if (tmp->token == PIPE && !tmp->next)
		return (print_error(3, NULL), -1);
	while (tmp)
	{
		if (tmp->token == PIPE)
		{
			if (!tmp->prev)
				return (print_error(3, NULL), -1);
			if (tmp->prev->token == R_REDIR
				|| tmp->prev->token == DR_REDIR)
				return (print_error(4, NULL), -1);
			if (!tmp->next || tmp->next->token == PIPE)
				return (print_error(3, NULL), -1);
			if (tmp->next->token == R_REDIR
				|| tmp->next->token == DR_REDIR)
				return (print_error(4, NULL), -1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	redir_check(t_Minishell *minishell)
{
	t_Command	*tmp;

	tmp = minishell->command;
	if (!tmp)
		return (-1);
	if (!tmp->next && tmp->token != PIPE && tmp->token != TEXT)
		return (print_error(4, NULL), -1);
	while (tmp)
	{
		if (tmp->token != PIPE && tmp->token != TEXT)
		{
			if (!tmp->prev || !tmp->next
				|| tmp->next->token != TEXT)
				return (print_error(4, NULL), -1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	token_check(t_Minishell *minishell)
{
	if (pipe_check(minishell) == -1)
		return (1);
	if (redir_check(minishell) == -1)
		return (1);
	return (0);
}
