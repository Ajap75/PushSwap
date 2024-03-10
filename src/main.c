/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinejourdan-astruc <antoinejourdan-a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:22:48 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/10 17:34:48 by antoinejour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *begin_list)
{
	t_stack	*tmp;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		tmp = begin_list->next;
		free(begin_list);
		begin_list = tmp;
	}
	begin_list = NULL;
}
/*Go through the the list and free every elements, keeping track of the next
element in the chain by using a temporary pointer to element and updating the 
head of the stack when leaving the loop*/

void	ft_free_argv(char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}
/*Free every string in the array, then free the pointer to array*/

static void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_swap_a(stack_a);
		return ;
	}
	else if (ft_stack_size(*stack_a) == 3)
		ft_tiny_sort(stack_a);
	else if (ft_stack_size(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (ft_print_error("Error\n"), 0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!ft_check_input_error(argv))
	{
		ft_free_argv(argv, argc);
		return (0);
	}
	stack_a = ft_init_stack(stack_a, argv, argc);
	if (!is_stack_a_sorted(&stack_a))
		ft_sort(&stack_a, &stack_b);
	free_stack(stack_a);
}

/*This program aim to sort a list of number. First of all
 the parsing has to be done. 
 No arguments, empty string. 
 If only one arguments. ft_split is used.
 Then, the prog will begin the parsing.
 Anything that has been allocated must be freed. The stack_a and
 The pointer to array returned by ft_split. 
 A second parsing will be done in the ft_init_stqck (improvement due to the lack
 of effeciency of the is_there_double apply to a string with strcmp. Ex : 008, +8, 8)
 If the stack is not sorted, we will call ft_sort which calls the different algorithms 
 regarding the size of the stack. 
