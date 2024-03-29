/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:02:52 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/10 17:25:26 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input_error(char **str)
{
	if (!ft_check_number(str) || !ft_check_double(str) || !ft_limit_check(str))
		return (0);
	return (1);
}
/*Parsing functions must be true otherwise, the prog will stop, the error
message will be send to the 2nd exit.
!!! The check double fonction is not effcient enough. The number will be checked
again, once the stack has been initialized */

int	ft_check_number(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_is_a_number(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_double(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (str[i] && str[j])
	{
		while (j < i)
		{
			if (is_no_duplicate(str[i], str[j]) == 0)
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	ft_limit_check(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atol(str[i]) < INT_MIN || (ft_atol(str[i]) > INT_MAX))
		{
			ft_print_error("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
