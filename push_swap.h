/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:58:27 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/19 14:15:20 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>

long int	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int ft_verif_arg(int argc, char **argv);
int *ft_many_arg(int argc, char **argv);
int *ft_one_arg(char **argv);
int ft_size_b(int *a);
void push_a(int *a, int *b, int size_stack, int *number_a);
void push_b(int *a, int *b, int size_stack, int *number_a);
void rotate_a(int *a, int size_stack, int number_a);
void rotate_b(int *b, int size_stack, int number_a);
void rotate_r(int *a, int *b, int size_stack, int number_a);
void reverse_rotate_a(int *a, int size_stack, int number_a);
void reverse_rotate_b(int *b, int size_stack, int number_a);
void reverse_rotate_r(int *a, int *b, int size_stack, int number_a);
void swap_a(int *a, int size_stack, int number_a);
void swap_b(int *b, int size_stack, int number_a);
void swap_ss(int *a, int *b, int size_stack, int number_a);
int number_move_a(int *a, int size_stack, int number_a, int number);
int number_move_b(int size_stack, int number_a, int index);
int min_move(int *a, int *b, int size_stack, int number_a);
size_t	number_string(char const *s, char c);

#endif