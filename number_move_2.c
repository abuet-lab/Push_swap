/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_move_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:25:17 by abuet             #+#    #+#             */
/*   Updated: 2026/02/26 12:37:09 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *a, int size_stack, int number_a)
{
	int	index_a;
	int	min_number;
	int	min_index;

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

int	find_index(int *a, int size_stack, int number_a, int value)
{
	int	i;

	i = size_stack - number_a;
	while (i < size_stack)
	{
		if (a[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_min_value(int *a, int size_stack, int number_a)
{
	int	i;
	int	min;

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

int	find_max_value(int *a, int size_stack, int number_a)
{
	int	i;
	int	max;

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

int	optimal_rotation(int count, int number_a)
{
	if (count <= number_a / 2)
		return (count);
	return ((number_a - count) * -1);
}
