/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:49:49 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/05 14:37:16 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*a = second;
}

void	ft_swap_a(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
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
	swap_a (&node1);
	ft_print_stack (&node1);
}
*/
