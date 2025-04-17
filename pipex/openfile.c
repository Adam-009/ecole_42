/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:52:20 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/15 13:52:55 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../main.h"

void	error_msg_file(char *str1, char *str2)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("\n", 2);
}

int	open_infile(t_Struct *str)
{
	int	fd;

	fd = open(str->file1, O_RDONLY);
	str->fd1 = fd;
	if (str->fd1 == -1)
	{
		error_msg_file("File error: ", str->file1);
		return (1);
	}
	return (0);
}

int	open_outfile(t_Struct *str)
{
	int	fd;

	fd = open(str->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	str->fd2 = fd;
	if (str->fd2 == -1)
	{
		error_msg_file("File error: ", str->file2);
		return (1);
	}
	return (0);
}
