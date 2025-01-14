/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:24:55 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/08 17:52:41 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

int	error(int argc)
{
	if (argc == 1)
	{
		write (1, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write (1, "Too many arguments.\n", 20);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	text;
	char	*ptr;
	int		i;
	int		fd;

	ptr = &text;
	i = 0;
	if (error(argc) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}	
	while (read(fd, &ptr[i], 1) != 0)
		write (1, &ptr[i], 1);
	close(fd);
	return (0);
}
