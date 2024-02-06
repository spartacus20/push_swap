/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:55:20 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/31 12:28:59 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define SPACE ' '
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_sort
{
	int					current_position;
	int					final_index;
	int					push_price;
	int					cheapest;
	int					above_median;

}						t_sort;

typedef struct s_stack_node
{
	int					value;
	struct s_sort		*sort;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;

}						t_stack_node;

void					free_arr(char **args);
void					free_stack(t_stack_node **stack);
void					error_free(t_stack_node **stack, char **args,
							int only_2);
void					stack_init(t_stack_node **stack, char **args,
							int only_2);
void					stack_append(t_stack_node **stack, int nbr);
int						stack_is_sorted(t_stack_node *stack);
int						stack_size(t_stack_node *stack);
t_stack_node			*get_last_node(t_stack_node *head);
t_stack_node			*get_max_node(t_stack_node *stack);
t_stack_node			*get_min_node(t_stack_node *stack);
void					set_target_node(t_stack_node *stack_a,
							t_stack_node *stack_b);

// Error handling
int						error_num_repeated(t_stack_node *stack, int nbr);
int						error_systax(char *str);

// Rules
void					swap(t_stack_node **stack);
void					sa(t_stack_node **stack_A);
void					sb(t_stack_node **stack_B);
void					ss(t_stack_node **stack_A, t_stack_node **stack_B);
void					rotate(t_stack_node **stack);
void					ra(t_stack_node **stack_A);
void					rb(t_stack_node **stack_B);
void					rr(t_stack_node **stack_A, t_stack_node **stack_B);
void					reverse_rotate(t_stack_node **stack);
void					rra(t_stack_node **stack_A);
void					rrb(t_stack_node **stack_B);
void					rrr(t_stack_node **stack_A, t_stack_node **stack_B);
void					push(t_stack_node **dest, t_stack_node **src);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b);
void					pb(t_stack_node **stack_a, t_stack_node **stack_b);

// Alogorithm Utils
void					set_current_position(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
void					set_price(t_stack_node *stack_a, t_stack_node *stack_b);
void					calculate_best_push(t_stack_node *stack_a,
							t_stack_node *stack_b);
void					rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b, t_stack_node *cheapest);
void					reverse_rotate_both(t_stack_node **stack_a,
							t_stack_node **stack_b, t_stack_node *cheapest);
void					rotate_until_top_node(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
t_stack_node			*get_cheapest(t_stack_node *stack);

// Alogorithm

void					sort_three_nb(t_stack_node **stack);
void					sort_five_nb(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_big_nb(t_stack_node **stack_a,
							t_stack_node **stack_b);

#endif
