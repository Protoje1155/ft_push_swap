/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:05:32 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/10 15:45:24 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push 2 elements to b, sort b until three elements in a, sort three in a
void	sort_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) > 3 && !(check_sorted(stack_a)))
		pb(stack_b, stack_a, 0);
	if (ft_lstsize(stack_a) > 3 && !(check_sorted(stack_a)))
		pb(stack_b, stack_a, 0);
	if (ft_lstsize(stack_a) > 3 && !(check_sorted(stack_a)))
		sort_b_until_a_has_three(stack_a, stack_b);
	if (!(check_sorted(stack_a)))
		sort_three(stack_a);
}

void	push_two_lowest_num_to_b(t_list **a, t_list **b)
{
	int	low_idx;
	int	op_ra;
	int	op_rra;

	while (ft_lstsize(a) > 3)
	{
		op_ra = 0;
		op_rra = 0;
		low_idx = find_index(a, find_minimum_value(a));
		if (low_idx <= ft_lstsize(a) / 2)
			op_ra = low_idx;
		else
			op_rra = ft_lstsize(a) - low_idx;
		while (--op_ra > -1)
			ra(a, 0);
		while (--op_rra > -1)
			rra(a, 0);
		pb(b, a, 0);
	}
}

void	push_two_lowest_num_to_a(t_list **a, t_list **b)
{
	while (ft_lstsize(b) != 0)
		pa(a, b, 0);
}

void	sort_five(t_list **a, t_list **b)
{
	push_two_lowest_num_to_b(a, b);
	if (!check_sorted(a))
		sort_three(a);
	push_two_lowest_num_to_a(a, b);
}

//big sort, first sorts b descending than back to a
void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) == 2)
	{
		sa(stack_a, 0);
		return ;
	}
	else if (ft_lstsize(stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
	{
		sort_b(stack_a, stack_b);
		sort_a(stack_a, stack_b);
	}
}
