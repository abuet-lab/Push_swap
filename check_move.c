/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:17:44 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/26 11:58:16 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_val(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static int	real_cost(int ma, int mb)
{
	if (ma >= 0 && mb >= 0)
	{
		if (ma > mb)
			return (ma);
		return (mb);
	}
	if (ma <= 0 && mb <= 0)
	{
		if (abs_val(ma) > abs_val(mb))
			return (abs_val(ma));
		return (abs_val(mb));
	}
	return (abs_val(ma) + abs_val(mb));
}

int	min_move(int *a, int *b, int size_stack, int number_a)
{
	int	index_b;
	int	current_nb_move;
	int	min_move;
	int	indexb_min_move;

	index_b = number_a;
	indexb_min_move = number_a;
	min_move = 99999;
	while (index_b < size_stack)
	{
		current_nb_move = real_cost(move_a(a, size_stack, number_a, b[index_b]),
				move_b(size_stack, number_a, index_b));
		if (current_nb_move <= min_move)
		{
			min_move = current_nb_move;
			indexb_min_move = index_b;
		}
		index_b++;
	}
	return (indexb_min_move);
}
