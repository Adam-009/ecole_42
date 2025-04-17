/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:42:50 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/15 16:10:00 by ChatGPT         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	execute(t_Struct *str, char *path_comm, char *cmd_index)
{
	char	**cmd;

	cmd = ft_split(cmd_index, ' ');
	execve(path_comm, cmd, str->env);
	free_array(cmd);
	ft_putstr_fd("Command error: ", 2);
	ft_putstr_fd(cmd_index, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

void	first_process(t_Struct *str)
{
	char	*path_comm;

	path_comm = check_comm(str, 2);
	if (path_comm == NULL)
	{
		close_pipefd(str);
		exit(127);
	}
	if (open_infile(str) == 1)
	{
		close_pipefd(str);
		free(path_comm);
		exit(1);
	}
	dup2(str->pipefd[1], STDOUT_FILENO);
	dup2(str->fd1, STDIN_FILENO);
	close(str->fd1);
	close_pipefd(str);
	execute(str, path_comm, str->argv[2]);
	free(path_comm);
	exit(127);
}

void	last_process(t_Struct *str)
{
	char	*path_comm;

	path_comm = check_comm(str, str->argc - 2);
	if (open_outfile(str) == 1)
	{
		close_pipefd(str);
		free(path_comm);
		exit(1);
	}
	dup2(str->pipefd[0], STDIN_FILENO);
	dup2(str->fd2, STDOUT_FILENO);
	close(str->fd2);
	close_pipefd(str);
	if (path_comm != NULL)
		execute(str, path_comm, str->argv[str->argc - 2]);
	free(path_comm);
	exit(127);
}

void	pipex(t_Struct *str)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (pipe(str->pipefd) == -1)
	{
		ft_putstr_fd("pipe error\n", 2);
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == 0)
		first_process(str);
	pid2 = fork();
	if (pid2 == 0)
		last_process(str);
	close_pipefd(str);
	if (pid1 > 0)
		waitpid(pid1, &status1, 0);
	if (pid2 > 0)
		waitpid(pid2, &status2, 0);
	if (pid2 > 0 && WIFEXITED(status2))
		str->exit_status = WEXITSTATUS(status2);
}

int	main(int argc, char **argv, char **env)
{
	t_Struct	str;

	if (argc != 5)
	{
		ft_putstr_fd("Minimum args is 4\n", 2);
		return (0);
	}
	ft_bzero(&str, sizeof(t_Struct));
	str.file1 = argv[1];
	str.file2 = argv[argc - 1];
	str.argc = argc;
	str.argv = argv;
	str.env = env;
	str.exit_status = 0;
	pipex(&str);
	exit(str.exit_status);
}
