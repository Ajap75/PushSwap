/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:40:06 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/05 16:10:49 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	study_the_cheapest(t_stack **stack_b)
{
	t_stack	*cur;

	cur = *stack_b;
	while (cur->the_cheapest != 1)
		cur = cur->next;
	if (cur->above_median == 1 && cur->target_node->above_median == 1)
		return (1);
	else if (cur->above_median == 0 && cur->target_node->above_median == 0)
		return (0);
	else
		return (2);
}

int	ft_labs(long i)
{
	if (i < 0)
		return (i *= -1);
	else
		return (i);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (i *= -1);
	else
		return (i);
}
