/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 08:49:17 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/08 12:36:59 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

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

void	error(t_Struct *str, int exit_status, char *exit_msg, int msg_status)
{
	str->exit_status = exit_status;
	if (str->exit_msg != NULL)
	{
		free(str->exit_msg);
		str->exit_msg = ft_strdup(exit_msg);
	}
	else
		str->exit_msg = ft_strdup(exit_msg);
	str->msg_status = msg_status;
}

void	exit_program(t_Struct *str)
{
	if (str->pathtocmd1 == NULL && str->pathtocmd2 != NULL
		&& str->exit_status == 127)
		str->exit_status = 0;
	if (str->pathtocmd1)
	{
		free(str->pathtocmd1);
		str->pathtocmd1 = NULL;
	}
	if (str->pathtocmd2)
	{
		free(str->pathtocmd2);
		str->pathtocmd2 = NULL;
	}
	if (str->exit_msg != NULL)
	{
		if (str->exit_status == 1)
			perror(str->exit_msg);
		else
			ft_putstr_fd(str->exit_msg, 2);
		free(str->exit_msg);
	}
	exit(str->exit_status);
}
