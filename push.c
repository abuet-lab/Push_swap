/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:44:40 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/01/19 18:48:49 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verify
void push_b(int *a, int *b, int size_stack, int *number_a)
{
	int index_a;
	int index_b;

	if (*number_a == 0)
		return ;
	index_a = size_stack - *number_a;
	index_b = *number_a - 1;
	b[index_b] = a[index_a];
	write (1, "pa\n", 3);
	*number_a -= 1;
}

void push_a(int *a, int *b, int size_stack, int *number_a)
{
	(void) *a;
	(void) *b;
	(void) size_stack;

	if (*number_a == size_stack)
		return ;
	write (1, "pb\n", 3);
	*number_a += 1;
}
