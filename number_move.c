/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:42:54 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/21 19:29:20 by antoinebuet      ###   ########.fr       */
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

static int find_index(int *a, int size_stack, int number_a, int value)
{
	int i;	
	i = size_stack - number_a;
	while (i < size_stack)
	{
		if (a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int find_min_value(int *a, int size_stack, int number_a)
{
	int i;
	int min;	
	i = size_stack - number_a + 1;
	min = a[size_stack - number_a];
	while (i < size_stack)
	{
		if (a[i] < min)
		    min = a[i];
		i++;
	}
	return (min);
}

static int find_max_value(int *a, int size_stack, int number_a)
{
	int i;
	int max;	
	i = size_stack - number_a + 1;
	max = a[size_stack - number_a];
	while (i < size_stack)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

static int optimal_rotation(int count, int number_a)
{
	if (count <= number_a / 2)
		return (count);
	return ((number_a - count) * -1);
}

int move_a(int *a, int size_stack, int number_a, int number)
{
	int i;
	int count;
	int start;
	int min_val;

	min_val = find_min_value(a, size_stack, number_a);
	if (number > find_max_value(a, size_stack, number_a) || number < min_val)
	{
		count = find_index(a, size_stack, number_a, min_val)
		 - (size_stack - number_a);
		return (optimal_rotation(count, number_a));
	}
	start = size_stack - number_a;
	i = start;
	count = 0;
	while (i < size_stack - 1)
	{
		if (a[i] < number && number < a[i + 1])
		{
	    	return (optimal_rotation(count + 1, number_a));
		}
		i++;
		count++;
	}
	return (0);
}
