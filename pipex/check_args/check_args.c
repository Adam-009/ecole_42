/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:56:38 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/04 14:00:38 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	check_if_same(char *file1, char *file2, t_Struct *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (file1[i] == '.' || file1[i] == '/')
		i++;
	while (file2[j] == '.' || file2[j] == '/')
		j++;
	if (ft_strcmp(&file1[i], &file2[j]) == 0)
	{
		error(str, 0, "File must not be the same", 0);
		exit_program(str);
	}
	if (str)
		return ;
}

int	check_absolute_path(char *command, t_Struct *str, int cmd_index)
{
	if (access(command, F_OK) == 0)
	{
		if (cmd_index == 0)
			str->pathtocmd1 = ft_strdup(command);
		else
			str->pathtocmd2 = ft_strdup(command);
		return (1);
	}
	return (0);
}

int	command_exists(char *command, char **path, t_Struct *str, int cmd_index)
{
	char	*full_path;
	char	*tmp_path;
	int		i;

	if (command[0] == '/')
		return (check_absolute_path(command, str, cmd_index));
	if (!path)
		return (0);
	i = -1;
	while (path[++i])
	{
		tmp_path = ft_strjoin("/", command);
		full_path = ft_strjoin(path[i], tmp_path);
		free(tmp_path);
		if (access(full_path, F_OK) == 0)
		{
			if (cmd_index == 0)
				str->pathtocmd1 = full_path;
			else
				str->pathtocmd2 = full_path;
			return (1);
		}
		free(full_path);
	}
	return (0);
}

void	c_if_command_exist(char **comm, char **env, int size, t_Struct *str)
{
	char	**path;
	char	*temp;
	int		j;
	int		cmd_index;

	path = find_path(env);
	temp = NULL;
	j = 2;
	cmd_index = 0;
	while (j < size - 1)
	{
		temp = isole_command(comm[j]);
		if (!command_exists(temp, path, str, cmd_index))
			error(str, 127, "Command not found\n", 0);
		free(temp);
		j++;
		cmd_index++;
	}
	free_array(path);
}

void	check_args(char **commands, int size, char **env, t_Struct *str)
{
	check_if_same(commands[1], commands[size - 1], str);
	c_if_command_exist(commands, env, size, str);
}
