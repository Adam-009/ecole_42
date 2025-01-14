/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:41:33 by asaadi--          #+#    #+#             */
/*   Updated: 2024/09/29 11:54:28 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*createstrcol1(char *l1, char *l2, char *l3, char *l4)
{
	char	*colstring;

	colstring = malloc(sizeof(char) * 4);
	colstring[0] = l1[0];
	colstring[1] = l2[0];
	colstring[2] = l3[0];
	colstring[3] = l4[0];
	return (colstring);
}

char	*createstrcol2(char *l1, char *l2, char *l3, char *l4)
{
	char	*colstring;

	colstring = malloc(sizeof(char) * 4);
	colstring[0] = l1[1];
	colstring[1] = l2[1];
	colstring[2] = l3[1];
	colstring[3] = l4[1];
	return (colstring);
}

char	*createstrcol3(char *l1, char *l2, char *l3, char *l4)
{
	char	*colstring;

	colstring = malloc(sizeof(char) * 4);
	colstring[0] = l1[2];
	colstring[1] = l2[2];
	colstring[2] = l3[2];
	colstring[3] = l4[2];
	return (colstring);
}

char	*createstrcol4(char *l1, char *l2, char *l3, char *l4)
{
	char	*colstring;

	colstring = malloc(sizeof(char) * 4);
	colstring[0] = l1[3];
	colstring[1] = l2[3];
	colstring[2] = l3[3];
	colstring[3] = l4[3];
	return (colstring);
}
