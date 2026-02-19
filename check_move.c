/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:17:44 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/19 17:01:39 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_move_b(int size_stack, int number_a, int index)
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
		return (count);
	}
	return (0);
}

static int find_min(int *a, int size_stack, int number_a)
{
	int index_a;
	int min_number;
	int min_index;

	if (number_a <= 0)
		return (0);

	index_a = size_stack - number_a;
	min_number = a[index_a];
	min_index = index_a;
	while (index_a < size_stack)
	{
		if (a[index_a] < min_number)
		{
			min_number = a[index_a];
			min_index = index_a;
		}
		index_a++;
	}
	return (min_index);
}

int number_move_a(int *a, int size_stack, int number_a, int number)
{
	int index_a;
	int count;
	int min_index;

	count = 0;
	index_a = size_stack - number_a;
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
			return (count);
		}
		min_index++;
		count++;
	}
	count = 0;
	min_index = find_min(a, size_stack, number_a);
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
			return (count);
		}
		index_a++;
		count++;
	}
	return (1);
}

int min_move(int *a, int *b, int size_stack, int number_a)
{
	int index_b;
	int current_nb_move;
	int min_move;
	int indexb_min_move;
	
	index_b = number_a;
	current_nb_move = 0;
	indexb_min_move = 0;
	min_move = 0;
	while (index_b < size_stack)
	{
		current_nb_move =(number_move_b(size_stack, number_a, index_b)
		 + number_move_a(a, size_stack, number_a, b[index_b]));
		printf("\n current : %d", current_nb_move);
		
		if (current_nb_move <= min_move)
		{
			min_move = current_nb_move;
			indexb_min_move = index_b;
			printf("\n min_move : %d", indexb_min_move);
		}		
		index_b++;
	}
	return (indexb_min_move);
}

