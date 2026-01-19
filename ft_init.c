/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:15:14 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/01/18 18:16:42 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_verif_arg2(char *argv)
{
	int i = 0;

    while (argv[i])
    {
        while (argv[i] == ' ')
            i++;

        if (argv[i] == '\0')
            return 0;

        if (argv[i] == '+' || argv[i] == '-')
            i++;

        if (!(argv[i] >= '0' && argv[i] <= '9'))
            return 1;

        while (argv[i] >= '0' && argv[i] <= '9')
            i++;

        while (argv[i] == ' ')
            i++;
    }
    return 0;
}

int ft_verif_arg(int argc, char **argv)
{
	int i;
	int j;
	if (argc > 2)
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			while (argv[i][j])
			{
				if (!(argv[i][j] >= 48 && argv[i][j] <= 57 ))			
						return (write(1, "Error\n", 6), 1);
				j++;
			}
			i++;
		}
	}
	else if (argc == 2 && ft_verif_arg2(argv[1]) == 1)
		return (write(1, "Error\n", 6), 1);
	return (0);
}

static int ft_verif_doublon(int temp, int *a, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (a[i] == temp)
			return (1);
		i++;
	}
	return (0);
}
int *ft_many_arg(int argc, char **argv)
{
	int i;
	int *a;
	long int temp;
	int j;

	i = 1;
	j = 0;
	a = malloc((argc - 1)* sizeof(int));
	if (!a)
		return (NULL);
	while (i < argc)
	{
		 
		temp = ft_atoi(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (write(1, "Error\n", 6), free(a), NULL);
		if (ft_verif_doublon(temp, a, j) == 1)
			return (write(1, "Error\n", 6), free(a), NULL);
		a[j] =(int) temp;
			j++;
		i++;	
	}
	return (a);
}

int *ft_one_arg(char **argv)
{
	int *a;
	int argc;
	int j;
	char **temp_argv;

	argc = 1;
	j = 0;
	temp_argv = ft_split(argv[1], ' ');
	while (temp_argv[argc])
		argc++;
	a = ft_many_arg(argc, temp_argv);
	if (!a)
		return(NULL);
	while (j < argc)
	{
		free(temp_argv[j]);
		j++;
	}
	free(temp_argv);
	return (a);
}