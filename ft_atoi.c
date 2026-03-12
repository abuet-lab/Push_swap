/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuet <abuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:50:10 by antoinebuet       #+#    #+#             */
/*   Updated: 2026/03/12 16:28:30 by abuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> 

long int	ft_atoi(const char *nptr)
{
	int			i;
	char		neg;
	long int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (nptr[i] && ((nptr[i] > 8  && nptr[i] < 14) && nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		neg *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		result += (nptr[i] - 48);
		if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
		{
			if (!(result < INT_MAX && result > INT_MIN))
				return (2147483648);
			result *= 10;		
		} 
		i++;
	}
	return (result * neg);
}
