/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:06:51 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/10 18:43:11 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack **begin_stack)
{
	int		i;
	t_stack	*cur;

	cur = *begin_stack;
	i = 0;
	if (*begin_stack == NULL)
		return ;
	while (cur)
	{
		cur->position = i;
		i++;
		cur = cur->next;
	}
}

void	set_above_median(t_stack **begin_stack)
{
	int		median;
	t_stack	*cur;

	cur = *begin_stack;
	if (ft_stack_size(*begin_stack) % 2 == 0)
		median = ft_stack_size(*begin_stack) / 2;
	else
		median = (ft_stack_size(*begin_stack) + 1) / 2;
	while (cur)
	{
		if (cur->position <= median)
			cur->above_median = 0;
		else
			cur->above_median = 1;
		cur = cur->next;
	}
}
/* >= median is important because to reduce by one the number of action
 when the node is ON the median */

void	set_cost(t_stack **begin_stack)
{
	t_stack	*cur;

	cur = *begin_stack;
	while (cur)
	{
		if (cur->above_median == 0)
			cur->cost = cur->position;
		else
			cur->cost = ft_stack_size(*begin_stack) - cur->position;
		cur = cur->next;
	}
}
/*The cost to bring the elem at the top of the stack*/

void	set_target_node(t_stack **begin_stack_a, t_stack **begin_stack_b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		delta;

	cur_a = *begin_stack_a;
	cur_b = *begin_stack_b;
	delta = INT_MAX;
	while (cur_b)
	{
		while (cur_a)
		{
			if (cur_b->data < cur_a->data && (ft_labs((cur_a->data)
						- (cur_b->data) < delta)))
			{
				cur_b->target_node = cur_a;
				delta = ft_labs((cur_a->data) - (cur_b->data));
			}
			cur_a = cur_a->next;
		}
		if (delta == INT_MAX)
			cur_b->target_node = ft_stack_min(begin_stack_a);
		cur_b = cur_b->next;
		cur_a = *begin_stack_a;
		delta = INT_MAX;
	}
}
/*We must find for each elem of stack_b, a target node in stack_a. The target not of 
elem_b is the closest upper elem in stack_a. If there is no upper elem in stack_a, 
THe target node is the smallest.
For each elem in b, we will loop the entire stack_a updating the target node, each
time we find a a_elem even closer. (with a delta even smaller
than the previous target node find). If during the loop on A,
 the delta hasn't been changed, it means that there is no closest upper number of elem_b
 in A, so the target node is the min of A. */
