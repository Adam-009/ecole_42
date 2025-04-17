/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 07:47:31 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/17 13:30:55 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./my_libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./check_comm/check_comm.h"

typedef struct s_Struct
{
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
	int		argc;
	char	**argv;
	char	**env;
	int		pipefd[2];
	int		exit_status;
}	t_Struct;

char	*check_comm(t_Struct *str, int cmd_index);
void	close_pipefd(t_Struct *str);
void	free_array(char **array);
int		open_infile(t_Struct *str);
int		open_outfile(t_Struct *str);
int		count_commands(t_Struct *str);

#endif