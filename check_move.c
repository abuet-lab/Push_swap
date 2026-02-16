/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:17:44 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/16 16:10:30 by antoinebuet      ###   ########.fr       */
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

int number_move_a(int *a, int size_stack, int number_a, int number)
{
	int i;
	int count;

	count = 0;
	i = size_stack - number_a;
	if (number > a[size_stack - 1] && number_a > 0) // cas nb plus grand que le dernier
		return (count = 1);
	while ((a[i] < number) && (i < size_stack))
		i++;
	if (i == 1)
		return (1);
	if (i <= (number_a / 2)) // on monte (dans la première moitié)
		return (count = i * 2);
	else if (i > (number_a / 2))
	{
		while (a[i])
		{
			count++;
			i++;
		}
		return (count * 2 + 1);
	}
	return (0);
}

