/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:55 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/05 16:48:18 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ft_rotate_a(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
/*
void	ft_print_stack(t_stack **a)
{
	t_stack	*cur;

	if (a == NULL || *a == NULL)
		return ;
	cur = *a;
	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}
int	main (void)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = malloc(sizeof(t_stack));
	node1->prev = NULL;
	node1->next = NULL;
	node1->data = 10;

	node2 = malloc(sizeof(t_stack));
	node2->prev = NULL;
	node2->next = NULL;
	node2->data = 20;

	node3 = malloc (sizeof(t_stack));
	node3->prev = NULL;
	node3->next = NULL;
	node3->data = 5;

	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;

	ft_print_stack (&node1);
	rotate (&node1);
	printf("\n");
	ft_print_stack (&node1);
}
*/
