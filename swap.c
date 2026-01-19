/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:44:53 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/01/19 19:14:23 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//verify
void swap_a(int *a, int *b, int size_stack, int number_a)
{
	int index_a;
	int temp;
	(void) b;
	
	if (number_a < 2)
		return ;
	index_a = size_stack - number_a;
	temp = a[index_a];
	a[index_a] = a[index_a + 1];
	a[index_a + 1] = temp;
	write(1, "sa\n", 3);
}

void swap_b(int *a, int *b, int size_stack, int number_a)
{
	int index_b;
	int temp;
	(void) a;
	(void) size_stack;
	
	if ((size_stack - number_a) < 2)
		return ;
	index_b = number_a;
	temp = b[index_b];
	b[index_b] = b[index_b + 1];
	b[index_b + 1] = temp;
	write(1, "sb\n", 3);
}

void swap_ss(int *a, int *b, int size_stack, int number_a)
{
	int index_a;
	int index_b;
	int temp;
	
	if (((size_stack - number_a) < 2) && number_a < 2)
		return ;
	index_a = size_stack - number_a;
	index_b = number_a;
	temp = a[index_a];
	a[index_a] = a[index_a + 1];
	a[index_a + 1] = temp;
	index_b = number_a;
	temp = b[index_b];
	b[index_b] = b[index_b + 1];
	b[index_b + 1] = temp;
	write(1, "ss\n", 3);
}



