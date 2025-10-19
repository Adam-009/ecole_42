/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:26:50 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/22 11:48:02 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

t_token	ft_token(char *array)
{
	if (ft_strcmp(array, "|") == 0)
		return (PIPE);
	if (ft_strcmp(array, "<") == 0)
		return (L_REDIR);
	if (ft_strcmp(array, ">") == 0)
		return (R_REDIR);
	if (ft_strcmp(array, "<<") == 0)
		return (DL_REDIR);
	if (ft_strcmp(array, ">>") == 0)
		return (DR_REDIR);
	return (TEXT);
}

t_Command	*createnode(char *array)
{
	t_Command	*newnode;

	newnode = (t_Command *)malloc(sizeof(t_Command));
	if (!newnode)
		return (NULL);
	newnode->cmd = array;
	newnode->infile = 0;
	newnode->outfile = 1;
	newnode->token = ft_token(array);
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	addback(t_Command **head, t_Command *newnode)
{
	t_Command	*temp;

	if (!newnode)
		return ;
	if (!*head)
	{
		*head = newnode;
		newnode->prev = NULL;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
}

void	init_command_list(t_Command **command, char **array)
{
	int				i;
	t_Command		*temp;

	i = 0;
	temp = NULL;
	while (array[i])
	{
		temp = createnode(array[i++]);
		if (!temp)
			return ;
		addback(command, temp);
	}
}
