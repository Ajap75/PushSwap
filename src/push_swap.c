/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:06:51 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/06 17:57:31 by anastruc         ###   ########.fr       */
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
/*Is the first element the biggest ? yes -> put it at the bottom of the stack*/
/*Is the 2nd element the biggest ? yes -> put it at the bottom of the stack*/
/*No ? So the biggest node is the last one, nothing to do so.*/
/*Only two nodes to sort remain. Is the first one the biggest ?*/

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
/* verifier les set the cheapest
probleme sur le dernier tour*/
