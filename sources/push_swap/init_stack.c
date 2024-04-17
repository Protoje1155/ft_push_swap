/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:13:02 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:13:03 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_one_num(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}

void	ft_init_stack(t_list **stack, int argc, char **argv)
{
	char	**split;
	int		i;
	t_list	*new;

	i = 0;
	if (argc == 2 && !(check_for_one_num(argv[1])))
		split = ft_split(argv[1], ' ');
	else
	{
		split = argv;
		split++;
	}
	while (split[i])
	{
		new = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2 && !(check_for_one_num(argv[1])))
		ft_free_split(split);
}
