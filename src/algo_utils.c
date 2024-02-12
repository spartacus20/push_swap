/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:49:29 by jotomas-          #+#    #+#             */
/*   Updated: 2024/02/12 15:58:24 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = stack_size(stack) / 2;
	while (stack)
	{
		stack->sort->current_position = i;
		if (i <= centerline)
			stack->sort->above_median = 1;
		else
			stack->sort->above_median = 0;
		stack = stack->next;
		++i;
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
			stack_b->sort->push_price
				+= stack_b->target_node->sort->current_position;
		else
			stack_b->sort->push_price += len_a
				- (stack_b->target_node->sort->current_position);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			best_match_value;
	t_stack_node	*best_match;

	if (!stack)
		return ;
	best_match_value = LONG_MAX;
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
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			stack_b->target_node = get_min_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}
