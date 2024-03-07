/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/05 14:51:27 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_min(t_stack **begin_list)
{
	t_stack	*cur;
	t_stack	*min;
	int		mindata;

	cur = *begin_list;
	min = cur;
	mindata = cur->data;
	while (cur)
	{
		if (cur->data < mindata)
		{
			mindata = cur->data;
			min = cur;
		}
		cur = cur->next;
	}
	return (min);
}
