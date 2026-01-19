/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:45:38 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/01/19 19:26:25 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int *ft_init_a (int argc, char **argv)
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

int ft_size_b(int *a)
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
void ft_controller(int *a, int *b)
{
	int size_stack;
	int number_a;
	int i = 0;

	number_a = ft_size_b(a);
	size_stack = number_a;
	push_b(a, b, size_stack, &number_a);
	push_b(a, b, size_stack, &number_a);
	push_b(a, b, size_stack, &number_a);
	push_b(a, b, size_stack, &number_a);
	printf("b : ");
	i = 0;
	while (i < 5)
	{
		printf("%d", b[i]);	
		i++;
	}
	printf("\n");
	rotate_b(a, b, size_stack, number_a);
	i = 0;
	printf("a : ");
	while (i < 5)
	{
		printf("%d", b[i]);	
		i++;
	}
	printf("\n");
	reverse_rotate_b(a, b, size_stack, number_a);
	printf("b : ");
	i = 0;
	while (i < 5)
	{
		printf("%d", b[i]);	
		i++;
	}
	printf("\n");
	// printf("b : ");
	// i = 0;
	// while (i < 5)
	// {
	// 	printf("%d", b[i]);	
	// 	i++;
	// }
	// printf("\n");
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
	b = malloc (ft_size_b(a) * sizeof(int));
	if (!b)
		return (0);
	ft_controller(a, b);
	return (0);
}
