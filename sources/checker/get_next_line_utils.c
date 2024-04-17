/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:29:17 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/26 16:29:19 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_char(char *heap)
{
	int	i;

	i = -1;
	if (heap == NULL)
		return (0);
	while (heap[++i])
		if (heap[i] == '\n')
			return (1);
	return (0);
}

int	ft_remaining_heap_extension(char *heap, int *i)
{
	if (!heap)
		return (0);
	while (heap[*i] && heap[*i] != '\n')
		(*i)++;
	if (heap[*i] == '\n')
		(*i)++;
	else if (heap[*i] == '\0')
		return (0);
	if (heap[*i] == '\0')
		return (0);
	return (1);
}
