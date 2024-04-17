/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:47:45 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/05 17:47:53 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_node == NULL)
		return (NULL);
	new_node->content = data;
	new_node->next = NULL;
	return (new_node);
}
