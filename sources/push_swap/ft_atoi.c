/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:23:47 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/01 17:23:52 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	long	sign;
	long	result;
	long	i;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (result * sign);
}
