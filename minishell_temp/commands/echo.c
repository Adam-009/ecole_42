/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:22:22 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/23 14:32:38 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	f_echo(char *text, int arg)
{
	if (text == NULL && arg == 1)
		ft_printf("");
	else if (text == NULL && arg == 0)
		ft_printf("\n");
	else if (arg == 1 && ft_strcmp("-n", text) != 0)
		ft_printf("%s", text);
	else if (arg == 0 && ft_strcmp("-n", text) != 0)
		ft_printf("%s\n", text);
}
