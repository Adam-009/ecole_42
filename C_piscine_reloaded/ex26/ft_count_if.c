/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:15:20 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/08 17:48:34 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			n++;
		i++;
	}
	return (n);
}
