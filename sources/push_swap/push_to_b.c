/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:13:14 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:13:15 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_index_to_b(int best_a_idx, t_list **a, t_list **b)
{
	int	best_b_idx;

	best_b_idx = find_index_sort_top_a_to_b(a, b, best_a_idx);
	calc_and_do_op(a, b, best_a_idx, best_b_idx);
	pb(b, a, 0);
}

void	calc_and_do_op(t_list **a, t_list **b, int a_index, int b_index)
{
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
	calc_and_do_rr(a, b, op_ra, op_rb);
	calc_and_do_rrr(a, b, op_rra, op_rrb);
}

void	calc_and_do_rr(t_list **a, t_list **b, int op_ra, int op_rb)
{
	int	rr;
	int	temp;

	rr = 0;
	if (op_ra != 0 && op_rb != 0)
	{
		rr = calc_rr_or_rrr(op_ra, op_rb);
		temp = calc_op_ra(op_ra, op_rb);
		op_rb = calc_op_ra(op_rb, op_ra);
		op_ra = temp;
	}
	while (--op_ra > -1)
		ra(a, 0);
	while (--op_rb > -1)
		rb(b, 0);
	while (--rr > -1)
		do_rr(a, b, 0);
}

void	calc_and_do_rrr(t_list **a, t_list **b, int op_rra, int op_rrb)
{
	int	rrr;
	int	temp;

	rrr = 0;
	if (op_rra != 0 && op_rrb != 0)
	{
		rrr = calc_rr_or_rrr(op_rra, op_rrb);
		temp = calc_op_ra(op_rra, op_rrb);
		op_rrb = calc_op_ra(op_rrb, op_rra);
		op_rra = temp;
	}
	while (--op_rra > -1)
		rra(a, 0);
	while (--op_rrb > -1)
		rrb(b, 0);
	while (--rrr > -1)
		do_rrr(a, b, 0);
}

int	size_of(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
