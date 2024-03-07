/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:14:03 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/07 15:36:10 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(t_stack *stack, char **argv, int argc)
{
	int	i;
	int	res;

	i = 1;
	while (argv[i])
	{
		res = ft_add_back(&stack, ft_new_elem(ft_atol(argv[i]), 0));
		if (res == 0)
		{
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	if (argc == 2)
		ft_free_argv(argv, argc);
	ft_there_is_duplicate(&stack);
	return (stack);
}
/*The error case of param  = " " is handle here.
The split return is NULL -> the new argv[1] is NULL;
so the prog do not enter the loop and argc == 2,
--> the prog enter the if, free argv,
Then the protection in ft_there_is_duplicate ignit ft_print_error
and exit*/

static void	ft_print_error_and_exit(void)
{
	ft_print_error("Error\n");
	exit(0);
}

int	ft_there_is_duplicate(t_stack **begin_stack)
{
	t_stack	*cur_i;
	t_stack	*cur_j;

	if (*begin_stack == NULL || begin_stack == NULL)
		ft_print_error_and_exit();
	cur_j = *begin_stack;
	cur_i = (*begin_stack)->next;
	while (cur_i != NULL)
	{
		while (cur_j != cur_i && cur_j != NULL)
		{
			if (cur_i->data == cur_j->data)
			{
				ft_print_error("Error\n");
				free_stack(*begin_stack);
				exit(0);
			}
			cur_j = cur_j->next;
		}
		cur_j = *begin_stack;
		cur_i = cur_i->next;
	}
	return (1);
}
