/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:18:13 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/21 22:41:06 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorting(int *a, int *b, int size_stack, int *number_a)
{
	int sorting_index;
	int nb_move_a;
	int nb_move_b;

	sorting_index = min_move(a, b, size_stack, *number_a);
	nb_move_a = move_a(a, size_stack, *number_a, b[sorting_index]);
	nb_move_b = move_b(size_stack, *number_a, sorting_index);
	
	while (nb_move_a > 0 && nb_move_b > 0)
	{
		rotate_r(a, b, size_stack, *number_a);
		nb_move_a--;
		nb_move_b--;
	}
	while (nb_move_a < 0 && nb_move_b < 0)
	{
		reverse_rotate_r(a, b, size_stack, *number_a);
		nb_move_a++;
		nb_move_b++;
	}
	while (nb_move_a > 0)
	{
		rotate_a(a, size_stack, *number_a);
		nb_move_a--;
	}
	while (nb_move_a < 0)
	{
		reverse_rotate_a(a, size_stack, *number_a);
		nb_move_a++;
	}
	while (nb_move_b > 0)
	{
		rotate_b(b, size_stack, *number_a);
		nb_move_b--;
	}
	while (nb_move_b < 0)
	{	
		reverse_rotate_b(b, size_stack, *number_a);
		nb_move_b++;
	}
	push_a(a, b, size_stack, number_a);
}

void last_sorting(int *a, int size_stack, int number_a)
{
	int index;

	index = find_min(a, size_stack, number_a);
	if (index < number_a / 2  + (size_stack - number_a))
	{
		while (index > 0)
		{
			rotate_a(a, size_stack, number_a);
			index--;
		}
		return ;
	}
	while (index < size_stack)
	{
		reverse_rotate_a(a, size_stack, number_a);
		index++;
	}
}
