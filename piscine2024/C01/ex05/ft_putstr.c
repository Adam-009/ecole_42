/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:38:16 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/20 11:06:05 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	write (1, str, 7);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*mstr;	
	mstr = "bonjour";

	printf("main: %s\n", mstr);
	ft_putstr(mstr);
	return (0);
}*/
