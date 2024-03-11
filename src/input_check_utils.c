/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:02:52 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/11 09:00:56 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_is_a_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i
				+ 1] <= '9'))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0' && str[i
				+ 1] > '9'))
	{
		ft_print_error("Error\n");
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_print_error("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*Check if there is a sign and a number.
If there is a second sign, return error.
Then check if  the next characters are numbers*/

int	is_no_duplicate(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	res = s1[i] - s2[i];
	if (res == 0)
	{
		ft_print_error("Error\n");
		return (0);
	}
	return (1);
}
/*strcmp*/

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	res;
	long	digit;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		digit = str[i] - '0';
		res = res + digit;
		i++;
	}
	return (res * sign);
}
/*Long is used to avoid comparison problems in the prog*/
