/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:42:50 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/08 13:16:17 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	child_process(t_Struct *str)
{
	char	**cmd1;

	cmd1 = NULL;
	dup2(str->pipefd[1], STDOUT_FILENO);
	dup2(str->fd1, STDIN_FILENO);
	close(str->fd1);
	close(str->fd2);
	close(str->pipefd[0]);
	close(str->pipefd[1]);
	if (str->pathtocmd1 != NULL)
	{
		cmd1 = ft_split(str->argv[2], ' ');
		execve(str->pathtocmd1, cmd1, str->envp);
		free_array(cmd1);
	}
}

void	parent_process(t_Struct *str)
{
	char	**cmd2;

	cmd2 = NULL;
	dup2(str->pipefd[0], STDIN_FILENO);
	dup2(str->fd2, STDOUT_FILENO);
	close(str->fd1);
	close(str->fd2);
	close(str->pipefd[0]);
	close(str->pipefd[1]);
	if (str->pathtocmd2 != NULL)
	{
		cmd2 = ft_split(str->argv[3], ' ');
		execve(str->pathtocmd2, cmd2, str->envp);
		free_array(cmd2);
	}
}

void	pipex(t_Struct *str)
{
	int		f;
	char	**temp;

	temp = NULL;
	if (pipe(str->pipefd) == -1)
		error(str, 1, "Pipe error", 1);
	f = fork();
	if (f < 0)
		return ;
	else if (f == 0 && str->fd1 != -1)
		child_process(str);
	else if (f > 0)
	{
		temp = ft_split(str->argv[2], ' ');
		if (str->argv[2] && str->argv[2][0] != '\0')
			if (ft_strcmp(temp[0], "sleep") == 0)
				waitpid(f, NULL, 0);
		parent_process(str);
	}
	if (str->fd1 == -1)
	{
		close(str->pipefd[0]);
		close(str->pipefd[1]);
	}
	free_array(temp);
}

void	openfile(t_Struct *str)
{
	int	fd1;
	int	fd2;

	fd2 = open(str->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	str->fd2 = fd2;
	if (str->fd2 == -1)
	{
		error(str, 1, "File error", 0);
		close(str->fd2);
		close(str->fd1);
		exit_program(str);
	}
	fd1 = open(str->file1, O_RDONLY);
	str->fd1 = fd1;
	if (str->fd1 == -1)
	{
		if (str->exit_status == -1)
			error(str, 0, "File error\n", 1);
		close(str->fd1);
	}
	pipex(str);
	if (str->fd1 == -1)
		close(str->fd2);
}

int	main(int argc, char **argv, char **env)
{
	t_Struct	str;

	str.pathtocmd1 = NULL;
	str.pathtocmd2 = NULL;
	str.msg_status = -1;
	str.exit_msg = NULL;
	str.exit_status = -1;
	if (argc != 5)
	{
		error(&str, 0, "Minimum args is 4\n", 0);
		exit_program(&str);
	}
	ft_bzero(&str, sizeof(t_Struct));
	check_args(argv, argc, env, &str);
	str.file1 = argv[1];
	str.file2 = argv[argc - 1];
	str.argc = argc;
	str.argv = argv;
	str.envp = env;
	openfile(&str);
	exit_program(&str);
}
