/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:08:36 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/08 16:40:40 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_op(char *command, int index)
{
	if (command[index] == '|')
		return (1);
	if (command[index] == '>')
	{
		if (command[index + 1] == '>')
			return (2);
		return (1);
	}
	if (command[index] == '<')
	{
		if (command[index + 1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

int	count_arg(char *command)
{
	int	i;
	int	count;
	int	op_len;

	i = 0;
	count = 0;
	while (command[i])
	{
		i = skip_spaces(command, i);
		if (!command[i])
			break ;
		op_len = get_op_len(command, i);
		if (op_len)
		{
			count++;
			i += op_len;
		}
		else
		{
			i = skip_word(command, i);
			count++;
		}
	}
	return (count);
}

void	malloc_inside_array(char **array, char *command)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (command[i])
	{
		i = skip_spaces(command, i);
		if (!command[i])
			break ;
		if (check_op(command, i))
			len = malloc_operator(array, command, i, j);
		else
			len = malloc_word(array, command, i, j);
		if (len == -1)
			return (free_array(array));
		i += len;
		j++;
	}
}

void	tokenizer(char *command, t_Minishell *minishell)
{
	int		argc;

	argc = count_arg(command);
	if (argc == 0)
		return ;
	minishell->array = malloc(sizeof(char *) * (argc + 1));
	if (!minishell->array)
		return ;
	malloc_inside_array(minishell->array, command);
	if (minishell->array != NULL)
		put_values(command, minishell->array);
	minishell->array[argc] = NULL;
	init_command_list(&minishell->command, minishell->array);
}
