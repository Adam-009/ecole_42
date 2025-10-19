/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:31:58 by asaadi--          #+#    #+#             */
/*   Updated: 2025/09/04 19:01:10 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "../minishell.h"

int			check_op(char *command, int index);
void		put_values(char *command, char **array);
int			skip_spaces(char *command, int i);
int			skip_word(char *cmd, int i);
int			get_op_len(char *command, int i);
int			malloc_operator(char **array, char *cmd, int i, int j);
int			malloc_word(char **array, char *cmd, int i, int j);

/*
typedef struct s_ast_node
{
	char **cmd; // = (<, Makefile,< outfile1, < outfile2, cat, -e);
	char **args // (= cat, -e);
	int infile = -1; //( = 4 ouvert avec Makefile)
	int outfile = -1;
	/ etc..
	struct s_ast_node *left;
	struct s_ast_node *right;

}t_ast_node;

typedef enum e_token
{
	text	;
	pipe;
	&& ;
	||;
	(;
	);
}t_token

typedef struct s_token_lst
{
	char *word;
	t_token token_type;
	struc s_token_lst *next;
}t_token_lst;
*/

#endif
