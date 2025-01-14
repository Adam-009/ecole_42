/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oforcier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:01:04 by oforcier          #+#    #+#             */
/*   Updated: 2024/09/29 12:23:30 by oforcier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	**tab2(char **tab)
{

	tab[12] = "3124";
	tab[13] = "3142";
	tab[14] = "3214";
	tab[15] = "3241";
	tab[16] = "3412";
	tab[17] = "3421";
	tab[18] = "4123";
	tab[19] = "4132";
	tab[20] = "4213";
	tab[21] = "4231";
	tab[22] = "4312";
	tab[23] = "4321";
	printf("%s\n", tab[0]);
	return(0);
}

char	**tab1(void)
{
	static char	*tab[24];

	tab[0] = "1234";
	tab[1] = "1243";
	tab[2] = "1324";
	tab[3] = "1342";
	tab[4] = "1423";
	tab[5] = "1432";
	tab[6] = "2134";
	tab[7] = "2143";
	tab[8] = "2314";
	tab[9] = "2341";
	tab[10] = "2413";
	tab[11] = "2431";
	tab2(tab);
	return(tab);
}


void	brute_force3()
{
	int	i;

	i = 0;
	tab();
	while (test(tab[i], array[11], array[15] != 1))
	{
		

void	brute_force2()
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (test(tab[i], array[9], array[13]) != 1)
	{
		while (test(tab[j], array[10], array[14] != 1))
		{
			brute_force3()
		}
	}
}

void	brute_force(char *array)
{
	char	***tab;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	tab = tab();
	while (final_test(l1, l2, l3, l4) != 1)
	{
		while (test(tab[i][j], array[8], array[12]) != 1)
		{
			brute_force2()
		j++;
		}
	}
}

int	main(void)
{
	tab1();
	return (0);
}
