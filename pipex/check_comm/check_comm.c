/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:05:36 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/15 15:23:04 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../main.h"

char	**find_path(char **env)
{
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (ft_split(&env[i][5], ':'));
		i++;
	}
	return (NULL);
}

char	*comm_without_arg(char *command)
{
	int	i;

	i = 0;
	while (command[i] && command[i] != ' ')
		i++;
	return (ft_substr(command, 0, i));
}

char	*check_full_path(char *path)
{
	if (access(path, F_OK | X_OK) == 0)
		return (ft_strdup(path));
	return (NULL);
}

char	*check_if_exist(char *comm, char **paths)
{
	int		i;
	char	*tmp_path;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		tmp_path = ft_strjoin("/", comm);
		if (!tmp_path)
			return (NULL);
		full_path = ft_strjoin(paths[i], tmp_path);
		free(tmp_path);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*check_comm(t_Struct *str, int cmd_index)
{
	char	**paths;
	char	*comm;
	char	*path;

	if (str->argv[cmd_index][0] == '/')
		return (handle_direct_path(str->argv[cmd_index]));
	paths = find_path(str->env);
	comm = comm_without_arg(str->argv[cmd_index]);
	if (!comm || !paths)
	{
		free_everything(comm, paths);
		return (NULL);
	}
	path = check_if_exist(comm, paths);
	if (!path || comm[0] == '\0')
	{
		if (path)
			free(path);
		error_msg_comm("Command error: ", str->argv[cmd_index]);
		free_everything(comm, paths);
		return (NULL);
	}
	free_everything(comm, paths);
	return (path);
}
