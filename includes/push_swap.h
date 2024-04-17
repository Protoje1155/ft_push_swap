/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:11:03 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:11:05 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list **lst);
int		ft_print_error(void);
int		check_arg_for_errors(int argc, char **split);
int		check_sorted(t_list **stack_a);
int		find_index(t_list **lst, int value);
int		find_minimum_value(t_list **lst);
int		find_maximum_value(t_list **lst);
int		find_value_from_index(t_list **a, int j);
int		check_op(int op_ra, int op_rb, int op_rra, int op_rrb);
int		calc_rr_or_rrr(int op_ra, int op_rb);
int		calc_op_ra(int op_ra, int op_rb);
int		calc_operations(t_list **a, t_list **b, int a_index, int b_index);
int		find_maximum_minimum_pos(int value, t_list **stack_b);
int		find_max_min_pos_for_b(int value, t_list **stack_a);
int		find_index_sort_top_a_to_b(t_list **a, t_list **b, int best_a_idx);
int		find_index_sort_top_b_to_a(t_list **stack_a, t_list **stack_b, int j);
int		check_for_one_num(char *s);
int		size_of(char *s);
long	ft_atoi(const char *nptr);

void	ft_init_stack(t_list **stack_a, int argc, char **argv);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	print_list(t_list **lst);
void	free_list(t_list **lst);
void	ft_free_split(char **split);
void	sa(t_list **lst, int i);
void	sb(t_list **lst, int i);
void	do_ss(t_list **a, t_list **b, int i);
void	pa(t_list **stack_a, t_list **stack_b, int i);
void	pb(t_list **stack_b, t_list **stack_a, int i);
void	ra(t_list **stack_a, int i);
void	rb(t_list **stack_b, int i);
void	rra(t_list **stack_a, int i);
void	rrb(t_list **stack_b, int i);
void	sort_three(t_list **lst);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	do_rr(t_list **stack_a, t_list **stack_b, int i);
void	do_rrr(t_list **stack_a, t_list **stack_b, int i);
void	sort_b_until_a_has_three(t_list **stack_a, t_list **stack_b);
void	calc_and_do_rrr(t_list **a, t_list **b, int op_rra, int op_rrb);
void	calc_and_do_rr(t_list **a, t_list **b, int op_ra, int op_rb);
void	calc_and_do_op(t_list **a, t_list **b, int a_index, int b_index);
void	push_index_to_b(int best_a_idx, t_list **a, t_list **b);
char	**ft_split(char const *s, char c);
void	push_back_to_a(t_list **stack_a, t_list **stack_b);
void	rotate_a_until_sorted(t_list **a);
void	sort_a(t_list **stack_a, t_list **stack_b);
void	rotate_a_idx_to_top(t_list **stack_a, int i);
void	check_line(t_list **a, t_list **b, char *line);
void	check_ops(t_list **a, t_list **b, char *line);
void	checker_func(t_list **a, t_list **b);
void	check_ss(char *s, t_list **a, t_list **b);
void	check_rr(char *s, t_list **a, t_list **b);
void	push_two_lowest_num_to_a(t_list **a, t_list **b);
void	push_two_lowest_num_to_b(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
t_list	*ft_lstnew(int data);
#endif
