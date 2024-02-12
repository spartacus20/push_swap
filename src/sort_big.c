/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:59:42 by jotomas-          #+#    #+#             */
/*   Updated: 2024/02/12 15:38:29 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_nodes(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->sort->above_median
		&& cheapest_node->target_node->sort->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->sort->above_median)
		&& !(cheapest_node->target_node->sort->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	rotate_until_top_node(stack_b, cheapest_node, 'b');
	rotate_until_top_node(stack_a, cheapest_node->target_node, 'a');
	pa(stack_a, stack_b);
}

void	sort_big_nb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_size(*stack_a);
	if (len_a == 5)
		sort_five_nb(stack_a, stack_b);
	else
	{
		while (len_a-- > 3)
			pb(stack_a, stack_b);
	}
	sort_three_nb(stack_a);
	while (*stack_b)
	{
		calculate_best_push(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	set_current_position(*stack_a);
	smallest = get_min_node(*stack_a);
	if (smallest->sort->above_median)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}
