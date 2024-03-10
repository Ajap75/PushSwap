/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:06:51 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/10 18:16:09 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny_sort(t_stack **stack)
{
	if (ft_stack_size(*stack) != 3)
		return ;
	if (((*stack)->next->data > (*stack)->data)
		&& ((*stack)->next->data > (*stack)->next->next->data))
	{
		ft_reverse_rotate_a(stack);
	}
	else if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->data > (*stack)->next->next->data))
	{
		ft_rotate_a(stack);
	}
	if ((*stack)->data > (*stack)->next->data)
		ft_swap_a(stack);
}
/*Sort three elem. Find the smallest. If it's the fst one --> rotate
if it's the second --> RR,
Otherwise it's the last one, no need to do anything.
Then just compare the two first number and swap if the ordre is not good.
Two action at most*/

/*Is the first element the biggest ? yes -> put it at the bottom of the stack*/
/*Is the 2nd element the biggest ? yes -> put it at the bottom of the stack*/
/*No ? So the biggest node is the last one, nothing to do so.*/
/*Only two nodes to sort remain. Is the first one the biggest ?*/

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	while (ft_stack_size(*stack_a) > 3)
	{
		set_position(stack_a);
		set_above_median(stack_a);
		min = ft_stack_min(stack_a);
		while ((*stack_a) != min)
		{
			if ((min)->above_median == 0)
				ft_rotate_a(stack_a);
			else
				ft_reverse_rotate_a(stack_a);
			set_position(stack_a);
		}
		ft_push_b(stack_a, stack_b);
	}
	ft_tiny_sort(stack_a);
	ft_push_a(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
}
/*Sort five elements. Find a way to use tiny sort. 
We locate the two smallest elem of the stack (loop condition)
and we move them to b. Check the min position to the median
and act the most efficient way. 
Then  we simply tiny sort the three remaining elems, and we push back on A
The two smallest elem..*/

void	move_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int	result;

	result = study_the_cheapest(stack_b);
	if (result == 1)
		move_reverse_rotate_nodes(stack_a, stack_b);
	else if (result == 0)
		move_rotate_nodes(stack_a, stack_b);
	else if (result == 2)
		move_different_ways(stack_a, stack_b);
}
/*Decide which way to move stack_a and b
regarding the positions of the nodes and the target_node to the median.
Thanks to the return of the functions study_the_cheapest */

int	ft_break_point_location(t_stack **stack)
{
	t_stack	*break_point;

	if (*stack == NULL || stack == NULL)
		return (0);
	break_point = *stack;
	if (break_point->data > break_point->next->data)
	{
		while (break_point->data > break_point->next->data && break_point->next)
			break_point = break_point->next;
	}
	else
	{
		while (break_point->data < break_point->next->data && break_point->next)
			break_point = break_point->next;
	}
	if (break_point->above_median == 1)
		return (1);
	else
		return (0);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		break_point_location;

	if (ft_stack_size(*stack_a) < 150)
		pre_sort_in_two(stack_a, stack_b);
	else
		pre_sort_in_four(stack_a, stack_b);
	while (ft_stack_size(*stack_a) < 3)
		ft_push_a(stack_a, stack_b);
	ft_tiny_sort(stack_a);
	while (ft_stack_size(*stack_b) != 0)
	{
		set_nodes(stack_a, stack_b);
		move_nodes(stack_a, stack_b);
	}
	if (is_stack_a_sorted(stack_a) == 1)
		return ;
	break_point_location = ft_break_point_location(stack_a);
	while (is_stack_a_sorted(stack_a) == 0 && break_point_location == 0)
		ft_rotate_a(stack_a);
	while (is_stack_a_sorted(stack_a) == 0 && break_point_location == 1)
		ft_reverse_rotate_a(stack_a);
}
/*The prog has to be as efficient as possible. We will handle 4 different 
cases. 2, 3, 5 and 5+ elem.
How does Push Swap works ? 
We will create a structure for every number to sort. The structure will contain
multiple informations which will be used to sort the elems. Remember, we can only
apply those actions to the stack : swap, r, rr, p. 
1) We pre_sort the stack_a`s elems before moving them to stack_b by bloc.
2) We keep only 3 elems in stack_a to used them as the first target node for every
element in stack_b. (the code has to be modified. There is no need to push_a back
 three time due to an improvement to reduce the numnber of actiions)
3) Every time we move an element from b to a (move nodes),
we update the informations of every nodes in b and iterate until b is empty (set nodes).
4) We will end with a stack_a almost sorted. However the min and max may not be the first
and the last elem, we might need to rotate or reverse rotate. A way to optimize these
last actions is to locate the breaking_point regarding the median to decide if we'd better
to rotate or reverse rotate.*/

