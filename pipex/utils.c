/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 08:49:17 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/17 13:30:45 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

int	count_commands(t_Struct *str)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < str->argc - 1)
	{
		count++;
		i++;
	}
	return (count);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	close_pipefd(t_Struct *str)
{
	close(str->pipefd[0]);
	close(str->pipefd[1]);
}
