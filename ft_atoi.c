/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:50:10 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/01/17 19:02:46 by antoinebuet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *nptr)
{
	int	i;
	char		neg;
	long int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i]
		== '\n' || nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		neg *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result += (nptr[i] - 48);
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			result *= 10;
		i++;
	}
	return (result * neg);
}
