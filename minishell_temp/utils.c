/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:28:05 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/29 13:54:05 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	find_command(t_Minishell *minishell, int index)
{
	if (ft_strcmp(minishell->command[index], "pwd") == 0)
		f_pwd();
	else if (ft_strcmp(minishell->command[index], "env") == 0)
		f_env(minishell->envp);
}
