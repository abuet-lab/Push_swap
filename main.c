/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:45:38 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/02/23 16:51:41 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void first_sorting_a(int *a, int size_stack, int number_a)
{
	int i;

	i = (size_stack - number_a);
	if ((a[i] < a[i + 1]) && (a[i + 1] < a[i + 2]))
		return ;
	if (a[i] < a[i + 1])
			swap_a(a, size_stack, number_a);
	if (a[i] > a[i + 2])
		rotate_a(a, size_stack, number_a);
	if (a[i] > a[i + 1])
			swap_a(a, size_stack, number_a);
}

static int *ft_init_a(int argc, char **argv)
{
	int *a;

	if (argc == 2)
	{
		a = ft_one_arg(argv);
		if(!a)
			return(0);
	}
	else if (argc > 2)
	{
		a = ft_many_arg(argc, argv);
		if(!a)
			return(0);
	}
	else 
		return (0);
	return (a);
}

static int ft_size_stack(int argc, char **argv)
{
	int count;

	count = 0;
	if (argc == 2)
	{
		count = number_string( argv[1], ' ');
		return (count);
	}
	else if (argc > 2)
		return (count = argc - 1);
	return (0);
}

static void ft_controller(int *a, int *b, int argc, char **argv)
{
	int size_stack;
	int number_a;

	number_a = ft_size_stack(argc, argv);
	size_stack = number_a;
	while(number_a > 3) 
		push_b(a, b, size_stack, &number_a);
	first_sorting_a(a, size_stack, number_a);
	while (number_a != size_stack)
	 	sorting(a, b, size_stack, &number_a);
	last_sorting(a, size_stack, number_a);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;

	if (ft_verif_arg(argc, argv) != 0)
		return (0);
	a = ft_init_a(argc, argv);
	if (!a)
		return (0);
	b = malloc (ft_size_stack(argc, argv) * sizeof(int));
	if (!b)
		return (0);
	ft_controller(a, b, argc, argv);
	free(a);
	free(b);
	return (0);
}
