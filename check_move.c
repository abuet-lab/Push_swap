/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:17:44 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/16 15:03:10 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_move_a (int size_stack, int number_a, int index)
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


