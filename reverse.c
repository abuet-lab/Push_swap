/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:44:46 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/26 12:21:33 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(int *a, int size_stack, int number_a)
{
	int	index_a;
	int	temp;
	int	i;

	if (number_a < 2)
		return ;
	index_a = size_stack - number_a;
	temp = a[size_stack - 1];
	i = size_stack - 1;
	while (i > index_a)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[index_a] = temp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(int *b, int size_stack, int number_a)
{
	int	index_b;
	int	temp;
	int	i;

	if ((size_stack - number_a) < 2)
		return ;
	index_b = number_a;
	temp = b[size_stack - 1];
	i = size_stack - 1;
	while (i > index_b)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[index_b] = temp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_r(int *a, int *b, int size_stack, int number_a)
{
	int	index_a;
	int	temp;
	int	i;

	if (((size_stack - number_a) < 2) && (number_a < 2))
		return ;
	index_a = size_stack - number_a;
	temp = a[size_stack - 1];
	i = size_stack - 1;
	while (i > index_a)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[index_a] = temp;
	index_a = number_a;
	temp = b[size_stack - 1];
	i = size_stack - 1;
	while (i > index_a)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[index_a] = temp;
	write(1, "rrr\n", 4);
}
