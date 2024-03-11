/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:57:00 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/11 09:01:13 by anastruc         ###   ########.fr       */
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

/*The core of the functions is extracted due to norminette.
!!! We can not optimize the incrementation by inserting it in the
loop when using RR or R on both stack. Don't know why.
If we have decide to move the stacks in the same ways.
We find the_cheapest node in the stack which has been marked.
We move both nodes in the same way :
TIME smallest cost between the two nodes costs
Then move the node with the highest cost alone :
TIME (cost of these node) - (smallest cost between the two nodes costs).
If we call the fonctions move_different_ways, we know which node go where
Simply due to his position to the median.*/
