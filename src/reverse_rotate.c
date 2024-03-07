/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:55:57 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/05 15:30:12 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*seconde_last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
	{
		seconde_last = last;
		last = last->next;
	}
	*a = last;
	last->next = first;
	first->prev = last;
	seconde_last->next = NULL;
	last->prev = NULL;
}

void	ft_reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_ab(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

/*
// void	ft_print_stack (t_stack **a)
// {
// 	t_stack *cur;
// 	if (a == NULL || *a == NULL)
// 		return ;
// 	cur = *a;

// 	while (cur != NULL)
// 	{
// 		printf("%d\n", cur->data);
// 		cur = cur->next;
// 	}
// }
// int	main (void)
// {
// 	t_stack	*node1;
// 	// t_stack	*node2;
// 	// t_stack	*node3;

// 	node1 = malloc(sizeof(t_stack));
// 	node1->prev = NULL;
// 	node1->next = NULL;
// 	node1->data = 10;

// 	// node2 = malloc(sizeof(t_stack));
// 	// node2->prev = NULL;
// 	// node2->next = NULL;
// 	// node2->data = 20;

// 	// node3 = malloc (sizeof(t_stack));
// 	// node3->prev = NULL;
// 	// node3->next = NULL;
// 	// node3->data = 5;

// 	// node1->next = node2;
// 	// node2->prev = node1;
// 	// node2->next = node3;
// 	// node3->prev = node2;

// 	// node1->next = node2;
// 	// node2->prev = node1;

// 	ft_print_stack (&node1);
// 	reverse_rotate (&node1);
// 	printf("\n");
// 	ft_print_stack (&node1);
// }
*/
