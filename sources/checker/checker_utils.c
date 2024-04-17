/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:11:31 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:11:32 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ss(char *s, t_list **a, t_list **b)
{
	if (s[1] == 'a' && s[2] == '\n')
		sa(a, 1);
	else if (s[1] == 'b' && s[2] == '\n')
		sb(b, 1);
	else if (s[1] == 's' && s[2] == '\n')
		do_ss(a, b, 1);
	else
		ft_print_error();
}

void	check_rr(char *s, t_list **a, t_list **b)
{
	if (s[1] == 'a' && s[2] == '\n')
		ra(a, 1);
	else if (s[1] == 'b' && s[2] == '\n')
		rb(b, 1);
	else if (s[1] == 'r' && s[2] == '\n')
		do_rr(a, b, 1);
	else if (s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(a, 1);
	else if (s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrb(b, 1);
	else if (s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		do_rrr(a, b, 1);
	else
		ft_print_error();
}
