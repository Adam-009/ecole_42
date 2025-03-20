/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:55:59 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/18 09:56:19 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	f_revtargets(t_Node *shooters, t_Node *suspects)
{
	t_Node	*target;
	t_Node	*current_suspect;

	while (shooters)
	{
		target = NULL;
		current_suspect = suspects;
		if (shooters->value > f_min_max(suspects, 1)->value)
			shooters->target = f_min_max(suspects, 0);
		else
		{
			while (current_suspect)
			{
				if (current_suspect->value > shooters->value)
					if (!target || current_suspect->value < target->value)
						target = current_suspect;
				current_suspect = current_suspect->next;
			}
			if (target)
				shooters->target = target;
			else
				shooters->target = f_min_max(suspects, 1);
		}
		shooters = shooters->next;
	}
}
