/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:57:00 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/06 15:58:53 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_different_ways(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cur;
	int		j;
	int		i;

	j = 0;
	i = 0;
	cur = *stack_b;
	while (cur->the_cheapest != 1)
		cur = cur->next;
	if (cur->above_median == 1)
	{
		while (j++ < cur->cost)
			ft_reverse_rotate_b(stack_b);
		while (i++ < cur->target_node->cost)
			ft_rotate_a(stack_a);
	}
	else
	{
		while (j++ < cur->cost)
			ft_rotate_b(stack_b);
		while (i++ < cur->target_node->cost)
			ft_reverse_rotate_a(stack_a);
	}
	ft_push_a(stack_a, stack_b);
}

void	move_rotate_nodes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cur;
	int		j;

	j = 0;
	cur = *stack_b;
	while (cur->the_cheapest != 1)
		cur = cur->next;
	mrn_core(stack_a, stack_b, j, cur);
	ft_push_a(stack_a, stack_b);
}

void	mrn_core(t_stack **stack_a, t_stack **stack_b, int j, t_stack *cur)
{
	if (cur->cost < cur->target_node->cost)
	{
		while (j < cur->cost)
		{
			ft_rotate_ab(stack_a, stack_b);
			j++;
		}
		while (j++ < cur->target_node->cost)
			ft_rotate_a(stack_a);
	}
	else
	{
		while (j < cur->target_node->cost)
		{
			ft_rotate_ab(stack_a, stack_b);
			j++;
		}
		while (j++ < cur->cost)
			ft_rotate_b(stack_b);
	}
}

void	move_reverse_rotate_nodes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cur;
	int		j;

	j = 0;
	cur = *stack_b;
	while (cur->the_cheapest != 1)
		cur = cur->next;
	mrrn_core(stack_a, stack_b, j, cur);
	ft_push_a(stack_a, stack_b);
}

void	mrrn_core(t_stack **stack_a, t_stack **stack_b, int j, t_stack *cur)
{
	if (cur->cost < cur->target_node->cost)
	{
		while (j < cur->cost)
		{
			ft_reverse_rotate_ab(stack_a, stack_b);
			j++;
		}
		while (j++ < cur->target_node->cost)
			ft_reverse_rotate_a(stack_a);
	}
	else
	{
		while (j < cur->target_node->cost)
		{
			ft_reverse_rotate_ab(stack_a, stack_b);
			j++;
		}
		while (j++ < cur->cost)
			ft_reverse_rotate_b(stack_b);
	}
}
