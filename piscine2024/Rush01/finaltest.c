/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finaltest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:56:47 by ascordil          #+#    #+#             */
/*   Updated: 2024/09/29 19:05:03 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int		ft_view(char *output);
char	*reversestr(char *str);
char	*createstrcol1(char *l1, char *l2, char *l3, char *l4);
char	*createstrcol2(char *l1, char *l2, char *l3, char *l4);
char	*createstrcol3(char *l1, char *l2, char *l3, char *l4);
char	*createstrcol4(char *l1, char *l2, char *l3, char *l4);

char	*reversestr(char *str)
{
	char	*swapstring;

	swapstring = malloc(sizeof(char) * 4);
	swapstring[0] = str[3];
	swapstring[1] = str[2];
	swapstring[2] = str[1];
	swapstring[3] = str[0];
	return (swapstring);
}

int	test_row(char *ligne, char leftvalue, char rightvalue)
{
	int	leftv;
	int	rigthv;
	int	check;

	leftv = leftvalue - '0';
	rigthv = rightvalue - '0';
	check = 0;
	if (ft_view(ligne) == leftv)
		check++;
	if (ft_view(reversestr(ligne)) == rigthv)
		check++;
	if (check == 2)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char	*str = "4321";
	char	*newstr;

	printf("%d\n", test("1234",'1','4'));	
	return(0);


}
*/