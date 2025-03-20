/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:59:27 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/20 09:02:29 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "my_libft/libft.h"
//temp
# include <stdio.h>

typedef struct s_Node
{
	long int		value;
	int				medium;
	long int		moves_cost;
	struct s_Node	*target;
	struct s_Node	*next;
	struct s_Node	*prev;
}	t_Node;

void		init_sort(t_Node *list_a, t_Node *list_b, int v);
void		sort(t_Node *list_a, t_Node *list_b);
void		move_together(t_Node **list_a, t_Node **list_b, t_Node **node);
void		sort_3(t_Node **list_a);
void		croissant(t_Node **list_a);

void		f_medium(t_Node *list);
void		f_targets(t_Node *shooters, t_Node *suspects);
void		f_revtargets(t_Node *shooters, t_Node *suspects);
void		f_cost(t_Node *list_a, t_Node *list_b, int v);
int			f_cost2(t_Node *list, t_Node *node);
t_Node		*f_min_max(t_Node *list, int v);
int			f_szlist(t_Node *list);
t_Node		*f_last_node(t_Node *list);
t_Node		*f_cheap(t_Node *list);

int			ft_issorted(t_Node *list);
int			check_list(char **list);
int			check_ifal(char **list);
void		exit_program(char **value, t_Node **list_a, t_Node **list_b, int v);
void		init_lists(t_Node **list_a, int v, char **value);
t_Node		*createnode(long int num);
void		addback(t_Node **head, t_Node *newnode);
void		free_list(t_Node *list);

void		pa(t_Node **list_a, t_Node **list_b);
void		pb(t_Node **list_a, t_Node **list_b);

void		sa(t_Node **list_a, int v);
void		sb(t_Node **list_b, int v);
void		ss(t_Node **list_a, t_Node **list_b);

void		ra(t_Node **list_a, int v);
void		rb(t_Node **list_b, int v);
void		rr(t_Node **list_a, t_Node **list_b);

void		rra(t_Node **list_a, int v);
void		rrb(t_Node **list_b, int v);
void		rrr(t_Node **list_a, t_Node **list_b);

#endif
