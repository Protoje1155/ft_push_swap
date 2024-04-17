/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:13:34 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:13:35 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_idx_to_top(t_list **stack_a, int i)
{
	int	op_rra;

	op_rra = 0;
	if (i == 0)
		op_rra = 0;
	else
		op_rra = ft_lstsize(stack_a) - i;
	while (--op_rra > -1)
		rra(stack_a, 0);
}
