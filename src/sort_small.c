/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:17:37 by jotomas-          #+#    #+#             */
/*   Updated: 2024/02/09 12:45:15 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_two_nb(t_stack_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_four_nb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	pb(stack_a, stack_b);
	sort_three_nb(stack_a);
	pa(stack_a, stack_b);
}

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
