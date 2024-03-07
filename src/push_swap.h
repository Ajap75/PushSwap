/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:52:34 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/06 11:01:28 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long				data;
	int					position;
	long				size_index;
	struct s_list		*target_node;
	int					cost;
	unsigned long long	total_cost;
	bool				above_median;
	bool				the_cheapest;
	bool				index_is_set;
	struct s_list		*next;
	struct s_list		*prev;
}						t_stack;

/*parsing*/
int						is_no_duplicate(char *s1, char *s2);
int						ft_is_a_number(char *str);
long					ft_atol(char *str);
int						ft_there_is_duplicate(t_stack **begin_stack);
char					**ft_split(char *str, char c);
/* check error fonctions */
int						ft_check_number(char **str);
int						ft_check_double(char **str);
int						ft_limit_check(char **str);
int						ft_check_input_error(char **str);
void					ft_print_error(char *str);

/* stack init and stack free and argv free */
int						ft_stack_size(t_stack *begin_list);
t_stack					*ft_new_elem(long nbr, long i);
int						ft_add_back(t_stack **begin_stack, t_stack *element);
t_stack					*ft_init_stack(t_stack *stack, char **argv, int argc);
int						is_stack_a_sorted(t_stack **begin_stack);
void					free_stack(t_stack *begin_list);
char					*ft_free(char **dest);
void					ft_free_argv(char **argv, int argc);

/*commands*/
void					ft_push_a(t_stack **a, t_stack **b);
void					ft_push_b(t_stack **a, t_stack **b);
void					ft_swap_a(t_stack **a);
void					ft_swap_b(t_stack **b);
void					ft_swap_ab(t_stack **a, t_stack **b);
void					ft_rotate_a(t_stack **a);
void					ft_rotate_b(t_stack **b);
void					ft_rotate_ab(t_stack **a, t_stack **b);
void					ft_reverse_rotate_a(t_stack **a);
void					ft_reverse_rotate_b(t_stack **b);
void					ft_reverse_rotate_ab(t_stack **a, t_stack **b);
void					swap(t_stack **a);
void					push(t_stack **a, t_stack **b);
void					rotate(t_stack **a);
void					reverse_rotate(t_stack **a);

/* sort algorithm */
void					ft_tiny_sort(t_stack **stack);
void					ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void					pre_sort_in_three(t_stack **stack_a, t_stack **stack_b);
void					pre_sort_in_two(t_stack **stack_a, t_stack **stack_b);
void					pre_sort_in_four(t_stack **stack_a, t_stack **stack_b);
void					push_swap(t_stack **stack_a, t_stack **stack_b);

/* Test */
void					ft_print_node(t_stack *a);
void					ft_print_stack_b(t_stack **a);
void					ft_print_stack_a(t_stack **a);
void					ft_print_stack(t_stack **a);

/* set node */
void					set_nodes(t_stack **stack_a, t_stack **stack_b);
void					set_position(t_stack **begin_stack);
void					set_target_node(t_stack **begin_stack_A,
							t_stack **begin_stack_B);
void					set_above_median(t_stack **begin_stack);
void					set_cost(t_stack **begin_stack);
t_stack					*ft_stack_min(t_stack **begin_list);
void					set_total_cost(t_stack **begin_stack);
void					set_the_cheapest(t_stack **begin_stack);
void					set_flag(t_stack **begin_stack, int min);
void					set_size_index(t_stack **begin_stack);
void					pre_sort_node_set(t_stack **stack_a);

/* set nodes and algorithm utils*/
int						ft_labs(long i);
int						ft_abs(int i);

/* move nodes */
int						study_the_cheapest(t_stack **stack_b);
void					move_different_ways(t_stack **stack_a,
							t_stack **stack_b);
void					move_rotate_nodes(t_stack **stack_a, t_stack **stack_b);
void					mrn_core(t_stack **stack_a, t_stack **stack_b, int j,
							t_stack *cur);

void					move_reverse_rotate_nodes(t_stack **stack_a,
							t_stack **stack_b);
void					mrrn_core(t_stack **stack_a, t_stack **stack_b, int j,
							t_stack *cur);
void					move_nodes(t_stack **stack_a, t_stack **stack_b);
void					move_quartil(t_stack **stack_a, t_stack **stack_b,
							int min, int max);

int						ft_break_point_location(t_stack **stack);

#endif
