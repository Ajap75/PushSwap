/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:58:43 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/10 18:51:04 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_total_cost(t_stack **begin_stack)
{
	int		cost_node_a;
	int		cost_node_b;
	t_stack	*cur;
	int		total_cost;

	cur = *begin_stack;
	while (cur)
	{
		cost_node_b = cur->cost;
		cost_node_a = cur->target_node->cost;
		if (cur->above_median == cur->target_node->above_median)
		{
			if (cost_node_b < cost_node_a)
				total_cost = cost_node_b;
			else
				total_cost = cost_node_a;
			total_cost += ft_abs(cost_node_b - cost_node_a);
		}
		else
			total_cost = cost_node_a + cost_node_b;
		cur->total_cost = total_cost;
		cur = cur->next;
	}
}

/*To determine the total cost,
 we have to handle two cases in this function
 1) above_median of the node and the target node are equal
  : We will be able to RR or RRR
 Which means the total cost is equal to the lowest of both cost
	+ the delta of the two costs
 which represent the number of action we'll have to make in adition
  of RRR and RR
 2) above_median of the node and the target node are NOT equal.
 We won't be able to perform RR or RRR which means that actions has
  to be done separetly on
 each of the stack, so the total cost is the sum of both costs.
 We iterate on stack_b to set up all the nodes total_cost*/

void	set_the_cheapest(t_stack **begin_stack)
{
	t_stack				*cur;
	t_stack				*minnode;
	unsigned long long	min;

	cur = *begin_stack;
	minnode = cur;
	min = cur->total_cost;
	if (cur->next)
		cur = cur->next;
	while (cur)
	{
		if (cur->total_cost < min)
		{
			min = cur->total_cost;
			minnode = cur;
		}
		else
		{
			cur->the_cheapest = 0;
		}
		cur = cur->next;
	}
	minnode->the_cheapest = 1;
}
/*the cheapest node in stack_b, is the node with the smalest 
total_cost. THe total cost, is the cost to put the node itself 
at the top of the stack_b AND the cost to bring the target node
in stack_a of this elem in stack_b. 
We loop on stack_b and we update the_cheapest every time we find 
a cheapest couple (node/target_node) smaller than the previous one*/

void	set_flag(t_stack **begin_stack, int min)
{
	t_stack	*cur;

	cur = *begin_stack;
	while (cur != NULL)
	{
		if (cur->data == min)
			cur->index_is_set = 1;
		cur = cur->next;
	}
}

void	set_size_index(t_stack **begin_stack)
{
	t_stack	*cur;
	int		min;
	int		i;

	min = INT_MAX;
	i = 1;
	cur = *begin_stack;
	while (i <= ft_stack_size(*begin_stack))
	{
		cur = *begin_stack;
		min = INT_MAX;
		while (cur != NULL)
		{
			if (cur->data < min && cur->index_is_set == 0)
			{
				cur->size_index = i;
				min = cur->data;
			}
			cur = cur->next;
		}
		set_flag(begin_stack, min);
		i++;
	}
}
/*we will give each node an index from 1 to stack_size in increasing order. 
We have to find each time we loop the smalest number of the stack excluding
the nodes already set (that's why each time we find a minus, we set_flag
 which set index_is_set of the node structure to 1)*/

void	set_nodes(t_stack **stack_a, t_stack **stack_b)
{
	set_position(stack_b);
	set_position(stack_a);
	set_above_median(stack_b);
	set_above_median(stack_a);
	set_cost(stack_b);
	set_cost(stack_a);
	set_target_node(stack_a, stack_b);
	set_total_cost(stack_b);
	set_the_cheapest(stack_b);
}
/*
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	// t_stack *min;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		stack_a = ft_init_stack(stack_a, argv);
		ft_push_b(&stack_a, &stack_b);
		ft_push_b(&stack_a, &stack_b);
		ft_push_b(&stack_a, &stack_b);
		ft_push_b(&stack_a, &stack_b);
		// set_position(&stack_a);
		// set_above_median(&stack_a);
		// set_cost(&stack_a);
		// set_position(&stack_b);
		// set_above_median(&stack_b);
		// set_cost(&stack_b);
		set_target_node(&stack_a, &stack_b);
		ft_print_stack_a(&stack_a);
		printf("\n");
		ft_print_stack_b(&stack_b);
		printf("\n");
		// ft_print_stack_a(&stack_a);
		// min = ft_stack_min(&stack_a);
		// printf("\n");
		// ft_print_node(min);
	}
}
*/
