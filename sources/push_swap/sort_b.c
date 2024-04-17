/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_helper_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:42:05 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/10 18:52:32 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//finds where the idx in a should be in b, if it is in the middle
int	find_max_min_pos(int value, t_list **stack_b)
{
	t_list	*b;
	int		i;
	int		temp;

	i = 0;
	b = *stack_b;
	temp = -2147483648;
	while (b != NULL)
	{
		if (value > b->content && temp < b->content)
			temp = b->content;
		b = b->next;
	}
	b = *stack_b;
	i = find_index(&b, temp);
	return (i);
}

//takes in every number of calculation to calculate the final num of operations
int	check_op(int op_ra, int op_rb, int op_rra, int op_rrb)
{
	int	rr;
	int	temp;
	int	rrr;

	if (op_ra != 0 && op_rb != 0)
	{
		rr = calc_rr_or_rrr(op_ra, op_rb);
		temp = calc_op_ra(op_ra, op_rb);
		op_rb = calc_op_ra(op_rb, op_ra);
		op_ra = temp;
	}
	else
		rr = 0;
	if (op_rra != 0 && op_rrb != 0)
	{
		rrr = calc_rr_or_rrr(op_rra, op_rrb);
		temp = calc_op_ra(op_rra, op_rrb);
		op_rrb = calc_op_ra(op_rrb, op_rra);
		op_rra = temp;
	}
	else
		rrr = 0;
	return (op_ra + op_rb + op_rra + op_rrb + rr + rrr);
}

//calculates the operations based of the 
// index where the element in a should be in b
int	calc_operations(t_list **a, t_list **b, int a_index, int b_index)
{
	int	res;
	int	op_ra;
	int	op_rb;
	int	op_rra;
	int	op_rrb;

	op_ra = 0;
	op_rb = 0;
	op_rra = 0;
	op_rrb = 0;
	if (a_index == 0)
		op_ra = 0;
	else if (a_index <= ft_lstsize(a) / 2)
		op_ra = a_index;
	else
		op_rra = ft_lstsize(a) - a_index;
	if (b_index == 0)
		op_rb = 0;
	else if (b_index <= ft_lstsize(b) / 2)
		op_rb = b_index;
	else
		op_rrb = ft_lstsize(b) - b_index;
	res = check_op(op_ra, op_rb, op_rra, op_rrb);
	return (res);
}

//calculates the index where the element in a should be in b
int	find_index_sort_top_a_to_b(t_list **a, t_list **b, int j)
{
	int		value;
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = *a;
	stack_b = *b;
	i = -1;
	value = find_value_from_index(&stack_a, j);
	if (value > find_maximum_value(&stack_b))
		i = find_index(&stack_b, find_maximum_value(&stack_b));
	else if (value < find_minimum_value(&stack_b))
		i = find_index(&stack_b, find_maximum_value(&stack_b));
	else
		i = find_max_min_pos(value, &stack_b);
	return (i);
}

//calculates the minimum amount of operation for each index 
// and pushes the index to b to have b sorted in descending order
void	sort_b_until_a_has_three(t_list **stack_a, t_list **stack_b)
{
	int		b_idx;
	t_list	*temp_a;
	int		a_idx;
	int		op;
	int		best_a_idx;

	while (ft_lstsize(stack_a) > 3)
	{
		op = 2147483647;
		a_idx = 0;
		temp_a = *stack_a;
		while (temp_a != NULL)
		{
			b_idx = find_index_sort_top_a_to_b(stack_a, stack_b, a_idx);
			if (op > calc_operations(stack_a, stack_b, a_idx, b_idx))
			{
				op = calc_operations(stack_a, stack_b, a_idx, b_idx);
				best_a_idx = a_idx;
			}
			a_idx++;
			temp_a = temp_a->next;
		}
		push_index_to_b(best_a_idx, stack_a, stack_b);
	}
}
