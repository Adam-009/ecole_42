/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:06:10 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/29 14:13:20 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	g_signal_data;

int	main(int argc, char **envp)
{
	t_Minishell	minishell;
	char		*line;

	minishell.envp = envp;
	minishell.command = NULL;
	ft_printf("%s\n", envp[1]);
	//f_env(envp);
	return (0);
	if (argc != 1)
		return (0);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			free(line);
			break ;
		}
		else if (line)
		{
			minishell.command = ft_split(line, ' ');
			find_command(&minishell, 0);
		}
		free(line);
		free (minishell.command);
	}
	if (envp)
		return (0);
}
