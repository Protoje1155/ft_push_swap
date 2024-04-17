/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:25:50 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/09 17:23:46 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if stack is sorted in ascending order
int	check_sorted(t_list **stack_a)
{
	t_list	*current;
	int		cmp;

	if (!*stack_a || !(*stack_a)->next)
		return (1);
	current = *stack_a;
	cmp = current->content;
	current = current->next;
	while (current != NULL)
	{
		if (cmp > current->content)
			return (0);
		cmp = current->content;
		current = current->next;
	}
	return (1);
}
