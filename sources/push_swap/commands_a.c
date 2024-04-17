/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:04:53 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/09 18:34:24 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_list **lst, int i)
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
		write(1, "sa\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*top_b;

	if (!*stack_b)
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	top_b->next = (*stack_a);
	*stack_a = top_b;
	if (i == 0)
		write(1, "pa\n", 3);
}

void	ra(t_list **stack_a, int i)
{
	t_list	*first;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = (*stack_a)->next;
	last->next = first;
	first->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rra(t_list **stack_a, int i)
{
	t_list	*last;
	t_list	*first;
	t_list	*sec;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	sec = *stack_a;
	while (sec->next->next != NULL)
		sec = sec->next;
	last = sec->next;
	*stack_a = last;
	last->next = first;
	sec->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}
