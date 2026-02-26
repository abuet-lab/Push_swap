/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:44:51 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/26 12:20:58 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *a, int size_stack, int number_a)
{
	int	index_a;
	int	temp;
	int	i;

	if (number_a < 2)
		return ;
	index_a = size_stack - number_a;
	temp = a[index_a];
	i = index_a;
	while (i < size_stack - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_stack - 1] = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(int *b, int size_stack, int number_a)
{
	int	index_b;
	int	temp;
	int	i;

	if ((size_stack - number_a) < 2)
		return ;
	index_b = number_a;
	temp = b[index_b];
	i = index_b;
	while (i < size_stack - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_stack - 1] = temp;
	write(1, "rb\n", 3);
}

void	rotate_r(int *a, int *b, int size_stack, int number_a)
{
	int	index_a;
	int	temp;
	int	i;

	if ((size_stack - number_a) < 2 && (number_a < 2))
		return ;
	index_a = size_stack - number_a;
	temp = a[index_a];
	i = index_a;
	while (i < size_stack - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_stack - 1] = temp;
	index_a = number_a;
	temp = b[index_a];
	i = index_a;
	while (i < size_stack - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_stack - 1] = temp;
	write(1, "rr\n", 3);
}
