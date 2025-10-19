/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:06:10 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/15 16:59:35 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	g_signal;

void	print_list(t_Minishell *minishell)
{
	t_Command	*tmp;

	tmp = minishell->command;
	while (tmp)
	{
		printf("%s: %i\n", tmp->cmd, tmp->token);
		tmp = tmp->next;
	}
}

void	init_fds(t_Minishell *mini)
{
	mini->fd[0] = dup(STDIN_FILENO);
	mini->fd[1] = dup(STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	t_Minishell	minishell;
	char		*line;

	minishell.envp = envp;
	minishell.array = NULL;
	if (argc != 1 || argv[1])
		return (0);
	init_fds(&minishell);
	while (1)
	{
		dup2(minishell.fd[0], STDIN_FILENO);
		dup2(minishell.fd[1], STDOUT_FILENO);
		minishell.command = NULL;
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)
			&& isatty(STDERR_FILENO))
			line = readline("minishell$ ");
		else
			line = get_next_line(0);
		if (!line || ft_strcmp(line, "exit") == 0)
		{
			free(line);
			free_list_cmd(&minishell);
			break ;
		}
		else if (line)
		{
			history(line);
			tokenizer(line, &minishell);
			//print_list(&minishell);
			pipex(&minishell, envp);
		}
		free(line);
		free_list_cmd(&minishell);
		free_array(minishell.array);
	}
	rl_clear_history();
}
