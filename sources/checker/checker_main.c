/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:11:23 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:11:24 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_line(t_list **a, t_list **b, char *line)
{
	if (line[0] == 's')
		check_ss(line, a, b);
	else if (line[0] == 'r')
		check_rr(line, a, b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(b, a, 1);
	else
		ft_print_error();
}

void	check_ops(t_list **a, t_list **b, char *line)
{
	char	*temp;

	while (line)
	{
		temp = line;
		check_line(a, b, temp);
		line = get_next_line(0);
		free(temp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!check_sorted(a))
		write(1, "KO\n", 3);
	else if (check_sorted(a) && *a)
		write(1, "OK\n", 3);
	free(line);
}

void	checker_func(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	if (line == NULL && !check_sorted(a))
		write(1, "KO\n", 3);
	else if (line == NULL && check_sorted(a))
		write(1, "OK\n", 3);
	else
		check_ops(a, b, line);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if ((argc == 2 && size_of(argv[1]) == 0) || argc == 1)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	if (!(check_arg_for_errors(argc, argv)))
		return (ft_print_error());
	ft_init_stack(&stack_a, argc, argv);
	checker_func(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
