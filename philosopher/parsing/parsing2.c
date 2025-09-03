/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:59:36 by asaadi--          #+#    #+#             */
/*   Updated: 2025/07/08 14:19:00 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../main.h"

int	c_characters(char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (c < '0' || c > '9')
			{
				printf("Invalid character detected: '%c'\n", c);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (c_characters(argv) == 1)
		return (1);
	if (c_number_of_philosophers(argv[1]) == 1)
		return (1);
	if (c_time_to_die(argv[2]) == 1)
		return (1);
	if (c_time_to_eat(argv[3]) == 1)
		return (1);
	if (c_time_to_sleep(argv[4]) == 1)
		return (1);
	if (argc == 6)
		if (c_notepme(argv[5]) == 1)
			return (1);
	return (0);
}
