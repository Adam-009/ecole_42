/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:30:26 by asaadi--          #+#    #+#             */
/*   Updated: 2025/05/28 12:36:25 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_spaces(char *command, int i)
{
	while (command[i] == ' ' || command[i] == '\t')
		i++;
	return (i);
}

static void	fill_operator(char *command, int i, char *dest, int op_len)
{
	int	k;

	k = 0;
	while (k < op_len)
	{
		dest[k] = command[i + k];
		k++;
	}
	dest[op_len] = '\0';
}

static void	fill_word(char *command, int *i, char *dest)
{
	int	v;

	v = 0;
	while (command[*i] && command[*i] != ' ' && command[*i] != '\t'
		&& check_op(command, *i) == 0)
	{
		dest[v] = command[*i];
		(*i)++;
		v++;
	}
	dest[v] = '\0';
}

void	put_values(char *command, char **array)
{
	int	i;
	int	j;
	int	op_len;

	i = 0;
	j = 0;
	while (command[i])
	{
		i = skip_spaces(command, i);
		if (command[i] == '\0')
			break ;
		op_len = check_op(command, i);
		if (!array[j])
			return ;
		if (op_len > 0)
		{
			fill_operator(command, i, array[j], op_len);
			i += op_len;
			j++;
			continue ;
		}
		fill_word(command, &i, array[j]);
		j++;
	}
	array[j] = NULL;
}
