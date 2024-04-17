/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:21:47 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/09 19:21:22 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **lst, int i)
{
	t_list	*first;
	t_list	*sec;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	sec = first->next;
	first->next = sec->next;
	sec->next = first;
	*lst = sec;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a, int i)
{
	t_list	*top_a;

	if (!*stack_a)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = (*stack_b);
	*stack_b = top_a;
	if (i == 0)
		write(1, "pb\n", 3);
}

void	rb(t_list **stack_b, int i)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = (*stack_b)->next;
	last->next = first;
	first->next = NULL;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b, int i)
{
	t_list	*last;
	t_list	*first;
	t_list	*sec;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	sec = *stack_b;
	while (sec->next->next != NULL)
		sec = sec->next;
	last = sec->next;
	*stack_b = last;
	last->next = first;
	sec->next = NULL;
	if (i == 0)
		write(1, "rrb\n", 4);
}
