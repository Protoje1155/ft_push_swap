/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:13:25 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:13:26 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_list **a, t_list **b)
{
	push_back_to_a(a, b);
	if (!check_sorted(a))
		rotate_a_until_sorted(a);
}

void	rotate_a_until_sorted(t_list **a)
{
	int	i;
	int	op_rra;
	int	op_ra;

	op_rra = 0;
	op_ra = 0;
	i = find_index(a, find_minimum_value(a));
	if (i == 0)
		op_ra = 0;
	else if (i <= ft_lstsize(a) / 2)
		op_ra = i;
	else
		op_rra = ft_lstsize(a) - i;
	while (--op_ra > -1)
		ra(a, 0);
	while (--op_rra > -1)
		rra(a, 0);
}

void	push_back_to_a(t_list **a, t_list **b)
{
	int	a_idx;

	while (ft_lstsize(b) != 0)
	{
		a_idx = find_index_sort_top_b_to_a(a, b, 0);
		rotate_a_idx_to_top(a, a_idx);
		pa(a, b, 0);
	}
}

int	find_index_sort_top_b_to_a(t_list **stack_a, t_list **stack_b, int j)
{
	int		value;
	int		i;
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	value = find_value_from_index(&b, j);
	if (value > find_maximum_value(&a))
		i = find_index(&a, find_minimum_value(&a));
	else if (value < find_minimum_value(&a))
		i = find_index(&a, find_minimum_value(&a));
	else
		i = find_max_min_pos_for_b(value, &a);
	return (i);
}

int	find_max_min_pos_for_b(int value, t_list **stack_a)
{
	t_list	*a;
	int		i;
	int		temp;

	i = 0;
	a = *stack_a;
	temp = 2147483647;
	while (a != NULL)
	{
		if (value < a->content && temp >= a->content)
			temp = a->content;
		a = a->next;
	}
	a = *stack_a;
	i = find_index(&a, temp);
	return (i);
}
