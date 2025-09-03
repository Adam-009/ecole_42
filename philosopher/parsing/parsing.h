/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:00:05 by asaadi--          #+#    #+#             */
/*   Updated: 2025/08/27 12:30:16 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int	c_notepme(char *arg);
int	c_time_to_sleep(char *arg);
int	c_time_to_eat(char *arg);
int	c_time_to_die(char *arg);
int	c_number_of_philosophers(char *arg);
int	parsing(int argc, char **argv);

#endif