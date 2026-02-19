/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:42:54 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/19 19:09:36 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int move_b(int size_stack, int number_a, int index)
{
	int number_b;
	int count;
	
	count = 0;
	number_b = size_stack - number_a;

	if (index <= (number_b / 2 + number_a))
	{
		while (index > number_a)
		{
			count++;
			index--;
		}
		return (count);
	}
	else if (index > (number_b / 2 + number_a))
	{
		while(index < size_stack)
		{
			index++;
			count++;
		}
		return (count * -1);
	}
	return (0);
}

static int move_a_middle(int *a, int size_stack, int number_a, int number)
{
	int count;
	int min_index;

	count = 0;
	min_index = find_min(a, size_stack, number_a);
	while (min_index < size_stack)
	{
		if (a[min_index] > number)
		{
			if (min_index <= number_a / 2  + (size_stack - number_a))
				return (count);
			count = 0;
			while (min_index < size_stack)
			{
				count++;
				min_index++;
			}
			return (count * -1);
		}
		min_index++;
		count++;
	}
	return (-999999);
}

static int move_a_start(int *a, int size_stack, int number_a, int number)
{
	int count;
	int min_index;
	int index_a;

	count = 0;
	min_index = find_min(a, size_stack, number_a);
	index_a = size_stack - number_a;
	while (index_a <= min_index)
	{
		if (a[index_a] < number)
		{
			if (index_a <= number_a / 2  + (size_stack - number_a))
				return (count);
			count = 0;
			while (index_a < size_stack)
			{
				count++;
				index_a++;
			}
			return (count * -1);
		}
		index_a++;
		count++;
	}
	return (-999999);
}

int move_a(int *a, int size_stack, int number_a, int number)
{
	int number_move;

	number_move = move_a_middle(a, size_stack, number_a, number);
	if (number_move == -999999)
		number_move = move_a_start(a, size_stack, number_a, number);
	if (number_move == -999999)
		return (0);
	return (number_move);
}


