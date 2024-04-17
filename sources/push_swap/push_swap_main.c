/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:04:31 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/10 15:40:55 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//main function checks for errors then initializes the unsorted stack
// sorts the stack
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc >= 2 && !(check_arg_for_errors(argc, argv)))
		return (ft_print_error());
	ft_init_stack(&stack_a, argc, argv);
	if (ft_lstsize(&stack_a) == 1)
	{
		free_list(&stack_a);
		return (0);
	}
	if (!(check_sorted(&stack_a)))
		sort_stack(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
