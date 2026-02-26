/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:42:54 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/26 12:49:08 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_b(int size_stack, int number_a, int index)
{
	int	number_b;
	int	count;

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
	while (index < size_stack)
	{
		index++;
		count++;
	}
	return (count * -1);
}

int	move_a(int *a, int size_stack, int number_a, int number)
{
	int	i;
	int	count;
	int	start;
	int	min_val;

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
