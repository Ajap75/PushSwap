/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:29:13 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/10 18:33:56 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_node_set(t_stack **stack_a)
{
	set_position(stack_a);
	set_above_median(stack_a);
	set_cost(stack_a);
}
/*Pre_sort needs those informations to work*/

void	move_quartil(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	t_stack	*cur;
	int		cost;

	cur = *stack_a;
	cost = 0;
	while (cur != NULL)
	{
		pre_sort_node_set(stack_a);
		if (cur->size_index >= min && cur->size_index <= max)
		{
			cost = cur->cost;
			while (cost-- > 0)
			{
				if (cur->above_median == 1)
					ft_reverse_rotate_a(stack_a);
				else
					ft_rotate_a(stack_a);
			}
			return (ft_push_b(stack_a, stack_b));
		}
		else
			cur = cur->next;
	}
	cur = *stack_a;
}

void	pre_sort_in_two(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size_a;
	int	median;
	int	i;

	i = 0;
	stack_size_a = ft_stack_size(*stack_a);
	median = stack_size_a / 2;
	set_size_index(stack_a);
	while (i++ < median)
		move_quartil(stack_a, stack_b, 1, median);
	i = 0;
	while (i++ <= median)
		move_quartil(stack_a, stack_b, median, stack_size_a - 3);
	i = 0;
}

void	pre_sort_in_four(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size_a;
	int	first_quartil;
	int	median;
	int	third_quartil;
	int	i;

	i = 0;
	stack_size_a = ft_stack_size(*stack_a);
	first_quartil = (stack_size_a) / 4;
	median = (stack_size_a) / 2;
	third_quartil = (stack_size_a) - (stack_size_a / 4);
	set_size_index(stack_a);
	while (i++ <= first_quartil)
		move_quartil(stack_a, stack_b, 1, first_quartil);
	i = 0;
	while (i++ <= first_quartil)
		move_quartil(stack_a, stack_b, third_quartil, stack_size_a);
	i = 0;
	while (i++ <= first_quartil)
		move_quartil(stack_a, stack_b, first_quartil, median);
	i = 0;
	while (i++ <= first_quartil)
		move_quartil(stack_a, stack_b, median, third_quartil);
}
// void	pre_sort_in_three(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	stack_size_a;
// 	int	first_tier;
// 	int	second_tier;
// 	int	i;

// 	i = 0;
// 	stack_size_a = ft_stack_size(*stack_a);
// 	first_tier = (stack_size_a) / 3;
// 	second_tier = (stack_size_a) - (stack_size_a / 3);
// 	set_size_index(stack_a);
// 	while (i++ < first_tier)
// 		move_quartil(stack_a, stack_b, first_tier, second_tier);
// 	i = 0;
// 	while (i++ < first_tier)
// 		move_quartil(stack_a, stack_b, 1, first_tier);
// 	i = 0;
// 	while (i++ <= first_tier)
// 		move_quartil(stack_a, stack_b, second_tier, stack_size_a);
// 	i = 0;
// }
