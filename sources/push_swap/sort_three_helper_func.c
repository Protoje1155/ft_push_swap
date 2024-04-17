/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:49:10 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/09 19:31:08 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	if (find_maximum_value(lst) == (*lst)->content)
	{
		ra(lst, 0);
		if (!check_sorted(lst))
			sa(lst, 0);
	}
	else if (find_minimum_value(lst) == (*lst)->content)
	{
		rra(lst, 0);
		sa(lst, 0);
	}
	else
	{
		if (find_index(lst, find_maximum_value(lst)) == 1)
			rra(lst, 0);
		else
			sa(lst, 0);
	}
}

int	find_minimum_value(t_list **lst)
{
	t_list	*current;
	int		i;

	current = *lst;
	i = current->content;
	while (current != NULL)
	{
		if (current->content < i)
			i = current->content;
		current = current->next;
	}
	return (i);
}

int	find_maximum_value(t_list **lst)
{
	int		i;
	t_list	*current;

	current = *lst;
	i = current->content;
	while (current != NULL)
	{
		if (current->content > i)
			i = current->content;
		current = current->next;
	}
	return (i);
}

int	find_index(t_list **lst, int value)
{
	t_list	*current;
	int		i;

	current = *lst;
	i = 0;
	while (current != NULL)
	{
		if (value == current->content)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

int	find_value_from_index(t_list **a, int j)
{
	t_list	*current;
	int		i;

	current = *a;
	i = 0;
	while (current != NULL)
	{
		if (i == j)
			return (current->content);
		i++;
		current = current->next;
	}
	return (-1);
}
