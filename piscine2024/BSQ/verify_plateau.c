/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_plateau.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:16:30 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/08 18:33:59 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	FILE	*ptr;
	char	*ptrfile;
	char	plateau;
	int		i;

	i = 0;
	ptrfile = "plateau.txt";
	ptr = fopen(ptrfile, "r");
	if (ptr == NULL)
		return (0);
	plateau = fgetc(&ptr);
	while (plateau != '\0')
	{
		printf("%c\n", plateau);
		plateau++;
	}
}
