/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:39:46 by asaadi--          #+#    #+#             */
/*   Updated: 2025/07/11 18:37:46 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	get_op_len(char *command, int i)
{
	if (check_op(command, i))
	{
		if (check_op(command, i) == 2)
			return (2);
		return (1);
	}
	return (0);
}

int	skip_word(char *cmd, int i)
{
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t'
		&& get_op_len(cmd, i) == 0)
		i++;
	return (i);
}

int	malloc_operator(char **array, char *cmd, int i, int j)
{
	int	op_len;
	int	k;

	if (check_op(cmd, i) == 2)
		op_len = 2;
	else
		op_len = 1;
	array[j] = malloc(sizeof(char) * (op_len + 1));
	if (!array[j])
		return (0);
	k = 0;
	while (k < op_len)
	{
		array[j][k] = cmd[i + k];
		k++;
	}
	array[j][op_len] = '\0';
	return (op_len);
}

int	malloc_word(char **array, char *cmd, int i, int j)
{
	int	start;
	int	len;
	int	k;

	start = i;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t' && check_op(cmd, i) == 0)
		i++;
	len = i - start;
	array[j] = malloc(sizeof(char) * (len + 1));
	if (!array[j])
		return (-1);
	k = -1;
	while (++k < len)
		array[j][k] = cmd[start + k];
	array[j][len] = '\0';
	return (len);
}
