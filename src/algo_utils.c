/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:49:29 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/30 16:06:17 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	half;

	if (!stack)
		return ;
	i = 0;
	half = stack_size(stack) / 2;
	while (stack)
	{
		stack->sort->current_position = i;
		if (i <= half)
			stack->sort->above_median = 1;
		else
			stack->sort->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_price(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	while (stack_b)
	{
		stack_b->sort->push_price = stack_b->sort->current_position;
		if (!(stack_b->sort->above_median))
			stack_b->sort->push_price = len_b
				- (stack_b->sort->current_position);
		if (stack_b->target_node->sort->above_median)
			stack_b->sort->push_price += stack_b->sort->current_position;
		else
			stack_b->sort->push_price += len_a
				- (stack_b->sort->current_position);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	int				best_match_value;
	t_stack_node	*best_match;

	if (!stack)
		return ;
	best_match_value = INT_MAX;
	while (stack)
	{
		if (stack->sort->push_price < best_match_value)
		{
			best_match_value = stack->sort->push_price;
			best_match = stack;
		}
		stack = stack->next;
	}
	best_match->sort->cheapest = 1;
}

void	set_target_node(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current;
	t_stack_node	*target;
	int				best_match_index;

	while (stack_b)
	{
		best_match_index = INT_MAX;
		current = stack_a;
		while (current)
		{
			if (current->value > stack_b->value
				&& current->value < best_match_index)
			{
				best_match_index = current->value;
				target = current;
			}
			current = current->next;
		}
		if (best_match_index == INT_MAX)
			stack_b->target_node = get_min_node(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}
