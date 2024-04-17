/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:47:23 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/08 17:06:14 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list **lst)
{
	int		i;
	t_list	*current;

	current = *lst;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

//free functions
void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
}

void	free_list(t_list **lst)
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/*
#include <stdio.h>
void	print_list(t_list **lst)
{
	t_list	*current;
	
	current = *lst;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}
*/
