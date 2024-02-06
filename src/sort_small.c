/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:17:37 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/30 15:57:27 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_three_nb(t_stack_node **stack)
{
	t_stack_node	*highest_node;

	highest_node = get_max_node(*stack);
	if (*stack == highest_node)
		ra(stack);
	else if ((*stack)->next == highest_node)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_five_nb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (stack_size(*stack_a) > 3)
	{
		calculate_best_push(*stack_a, *stack_b);
		rotate_until_top_node(stack_a, get_min_node(*stack_a), 'a');
		pb(stack_a, stack_b);
	}
}
