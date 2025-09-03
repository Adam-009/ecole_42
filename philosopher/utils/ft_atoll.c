/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:52:48 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/02 13:07:48 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../main.h"

int	parse_sign(const char **text)
{
	int	sign;

	sign = 1;
	while ((**text >= 9 && **text <= 13) || **text == 32)
		(*text)++;
	if (**text == 45 || **text == 43)
	{
		if (**text == 45)
			sign = -1;
		(*text)++;
	}
	return (sign);
}

long long int	convert_to_number(const char *text, int sign)
{
	long long int	result;

	result = 0;
	while (*text >= 48 && *text <= 57)
	{
		if (result > (LLONG_MAX - (*text - '0')) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		result = result * 10 + (*text - '0');
		text++;
	}
	return (result * sign);
}

long long int	ft_atoll(const char *text)
{
	int	sign;

	if (!text)
		return (0);
	sign = parse_sign(&text);
	return (convert_to_number(text, sign));
}
