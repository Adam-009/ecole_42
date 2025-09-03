/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:47:52 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/01 16:42:24 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	c_number_of_philosophers(char *arg)
{
	int	value;

	value = ft_atoll(arg);
	if (value <= 0 || value > 200)
		return (printf("number_of_philosophers is invalide\n"), 1);
	return (0);
}

int	c_time_to_die(char *arg)
{
	int	value;

	value = ft_atoll(arg);
	if (value <= 0 || value > INT_MAX)
		return (printf("time_to_die is invalide\n"), 1);
	return (0);
}

int	c_time_to_eat(char *arg)
{
	int	value;

	value = ft_atoll(arg);
	if (value <= 0 || value > INT_MAX)
		return (printf("time_to_eat is invalide\n"), 1);
	return (0);
}

int	c_time_to_sleep(char *arg)
{
	int	value;

	value = ft_atoll(arg);
	if (value <= 0 || value > INT_MAX)
		return (printf("time_to_sleep is invalide\n"), 1);
	return (0);
}

int	c_notepme(char *arg)
{
	int	value;

	value = ft_atoll(arg);
	if (value <= 0 || value > INT_MAX)
	{
		printf("number_of_times_each_philosopher_must_eat is invalide\n");
		return (1);
	}
	return (0);
}
