/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:11:47 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/15 15:11:48 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

//checks if num is a num
int	check_arg_for_nan(char **split)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while ((split[i][j] == '+' || split[i][j] == '-') && split[i][j])
			j++;
		if (j > 1 || split[i][j] == '\0')
			return (0);
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//checks if num is in range of an int
int	check_arg_is_int(char **split)
{
	long	num;
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		num = ft_atoi(split[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

//checks for duplicates
int	check_for_dup(char **split)
{
	int	temp_one;
	int	temp_two;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[j] != 0)
	{
		i = j + 1;
		temp_one = (int)ft_atoi(split[j]);
		while (split[i] != 0)
		{
			temp_two = (int)ft_atoi(split[i]);
			if (temp_one == temp_two)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

//main error function
int	check_arg_for_errors(int argc, char **argv)
{
	int		error;
	char	**split;

	if (argc == 2 && !(check_for_one_num(argv[1])))
		split = ft_split(argv[1], ' ');
	else
	{
		split = argv;
		split++;
	}
	error = 1;
	error = check_arg_for_nan(split);
	if (error == 0)
		return (0);
	error = check_arg_is_int(split);
	if (error == 0)
		return (0);
	error = check_for_dup(split);
	if (error == 0)
		return (0);
	if (argc == 2 && !(check_for_one_num(argv[1])))
		ft_free_split(split);
	return (error);
}
