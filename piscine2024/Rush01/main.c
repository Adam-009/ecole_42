/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:39:51 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/29 20:37:45 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_view(char *output);
int		ft_split(char *argv, char *array);
int		final_col(char *l1, char *l2, char *l3, char *l4);
int		test_row(char *ligne, char leftvalue, char rightvalue);
char	*reversestr(char *str);
char	*createstrcol1(char *l1, char *l2, char *l3, char *l4);
char	*createstrcol2(char *l1, char *l2, char *l3, char *l4);
char	*createstrcol3(char *l1, char *l2, char *l3, char *l4);
char	*createstrcol4(char *l1, char *l2, char *l3, char *l4);
void	create_lignes_three_four(char *lignes3, char *lignes4, char *ligne);
void	create_lignes_one_two(char *lignes1, char *lignes2, char *ligne);
int		final_col_concat_first(char *ligne, char *array);
int		final_col_concat_second(char *ligne, char *array);

int	main(int argc, char **argv)
{	
	char	*array;
	char	*str;

	array = malloc(sizeof(char) * 16);
	str = "4234434144124123";
	if ((argc == 2) && (ft_split(argv[1], array)))
	{
		printf("premiere %d\n", final_col_concat_first(str, array));
		printf("seconde %d\n", final_col_concat_second(str, array));
	}
	else
	{
		write (1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	ft_split(char *argv, char *array)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			array[j] = argv[i];
			j++;
		}
		if (argv[i + 1] == ' ')
			i += 2;
		else
			break ;
	}
	if ((j == 16) && !(argv[31]))
		return (1);
	else
		return (0);
}
/*
int	final_col(char *l1, char *l2, char *l3, char *l4)
{
	int	check;

	check = 0;
	if (((ft_view(createstrcol1(l1, l2, l3, l4))) == (g_array[0] - '0'))
		&& ((ft_view(reversestr(createstrcol1(l1, l2, l3, l4))))
			== (g_array[4] - '0')))
		check++;
	if (((ft_view(createstrcol2(l1, l2, l3, l4))) == (g_array[1] - '0'))
		&& ((ft_view(reversestr(createstrcol2(l1, l2, l3, l4))))
			== (g_array[5] - '0')))
		check++;
	if (((ft_view(createstrcol3(l1, l2, l3, l4))) == (g_array[2] - '0'))
		&& ((ft_view(reversestr(createstrcol3(l1, l2, l3, l4))))
			== (g_array[6] - '0')))
		check++;
	if (((ft_view(createstrcol4(l1, l2, l3, l4))) == (g_array[3] - '0'))
		&& ((ft_view(reversestr(createstrcol4(l1, l2, l3, l4))))
			== (g_array[7] - '0')))
		check++;
	if (check == 4)
		return (1);
	else
		return (0);
}
*/

void	create_lignes_one_two(char *lignes1, char *lignes2, char *ligne)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		lignes1[i] = ligne[j];
		lignes2[i] = ligne[j + 1];
		j += 4;
		i++;
	}
	lignes1[4] = '\0';
	lignes2[4] = '\0';
}

void	create_lignes_three_four(char *lignes3, char *lignes4, char *ligne)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (i < 4)
	{
		lignes3[i] = ligne[j];
		lignes4[i] = ligne[j + 1];
		j += 4;
		i++;
	}
	lignes3[4] = '\0';
	lignes4[4] = '\0';
}

int	final_col_concat_first(char *ligne, char *array)
{
	int		check;
	char	*ptone;
	char	*pttwo;
	char	ligne1[5];
	char	ligne2[5];

	ptone = ligne1;
	pttwo = ligne2;
	check = 0;
	create_lignes_one_two(ptone, pttwo, ligne);
	if (((ft_view(ligne1)) == (array[0] - '0'))
		&& ((ft_view(reversestr(ligne1))) == (array[4] - '0')))
		check++;
	if (((ft_view(ligne2)) == (array[1] - '0'))
		&& ((ft_view(reversestr(ligne2))) == (array[5] - '0')))
		check++;
	if (check == 2)
		return (1);
	return (0);
}

int	final_col_concat_second(char *ligne, char *array)
{
	int		check;
	char	*ptthree;
	char	*ptfour;
	char	ligne3[5];
	char	ligne4[5];

	ptthree = ligne3;
	ptfour = ligne4;
	create_lignes_three_four(ptthree, ptfour, ligne);
	check = 0;
	if (((ft_view(ligne3)) == (array[2] - '0'))
		&& ((ft_view(reversestr(ligne3))) == (array[6] - '0')))
		check++;
	if (((ft_view(ligne4)) == (array[3] - '0'))
		&& ((ft_view(reversestr(ligne4))) == (array[7] - '0')))
		check++;
	if (check == 2)
		return (1);
	return (0);
}
