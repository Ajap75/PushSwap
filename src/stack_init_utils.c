/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:03 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/06 17:59:10 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *begin_stack)
{
	if (begin_stack == NULL)
		return (0);
	else
		return (1 + ft_stack_size(begin_stack->next));
}

t_stack	*ft_new_elem(long nbr, long i)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->prev = NULL;
	elem->next = NULL;
	elem->data = nbr;
	elem->size_index = i;
	elem->index_is_set = 0;
	return (elem);
}

int	ft_add_back(t_stack **begin_stack, t_stack *element)
{
	t_stack	*cur;

	if (element == NULL)
		return (0);
	if (begin_stack)
	{
		if (*begin_stack)
		{
			cur = *begin_stack;
			while (cur->next)
			{
				cur = cur->next;
			}
			cur->next = element;
			element->prev = cur;
			element->next = NULL;
		}
		else
		{
			*begin_stack = element;
			element->prev = NULL;
			element->next = NULL;
		}
	}
	return (1);
}

int	is_stack_a_sorted(t_stack **begin_stack)
{
	t_stack	*cur;

	if (*begin_stack == NULL || begin_stack == NULL)
		return (1);
	cur = *begin_stack;
	while (cur->next)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}
