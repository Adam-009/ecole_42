/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:46:43 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/01 18:46:03 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_rules_struct(t_Rules *rules, int argc, char **argv)
{
	rules->number_of_philo = ft_atoll(argv[1]);
	rules->time_to_die = ft_atoll(argv[2]);
	rules->time_to_eat = ft_atoll(argv[3]);
	rules->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		rules->notepme = ft_atoll(argv[5]);
	else
		rules->notepme = -1;
	rules->time_start = timestamp();
	rules->status = 0;
}

void	init_structs(t_Rules *rules, t_Philos *philos,
	t_Forks *forks, t_Structs *structs)
{
	structs->forks = forks;
	structs->philos = philos;
	structs->rules = rules;
}
