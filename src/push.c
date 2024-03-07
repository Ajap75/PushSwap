/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:59:45 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/06 17:57:01 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	if (*a != NULL)
	{
		(*a)->prev = *b;
		(*b)->next = *a;
		*a = *b;
	}
	else
	{
		*a = ft_new_elem((*b)->data, (*b)->size_index);
		free((*b));
		if (*a == NULL)
		{
			free_stack(*a);
			free_stack(*b);
			exit(0);
		}
	}
	*b = tmp;
}

void	ft_push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
