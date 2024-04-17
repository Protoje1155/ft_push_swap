/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:12:17 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:12:19 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr(t_list **stack_a, t_list **stack_b, int i)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (i == 0)
		write(1, "rr\n", 3);
}

void	do_rrr(t_list **stack_a, t_list **stack_b, int i)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (i == 0)
		write(1, "rrr\n", 4);
}

void	do_ss(t_list **a, t_list **b, int i)
{
	sa(a, 1);
	sb(b, 1);
	if (i == 0)
		write (1, "ss\n", 3);
}

int	calc_rr_or_rrr(int op_ra, int op_rb)
{
	int	op_rr;

	if (op_ra > op_rb)
		op_rr = op_rb;
	else if (op_ra < op_rb)
		op_rr = op_ra;
	else
		op_rr = op_ra;
	return (op_rr);
}

int	calc_op_ra(int op_ra, int op_rb)
{
	if (op_ra > op_rb)
		op_ra = op_ra - op_rb;
	else
		op_ra = 0;
	return (op_ra);
}
