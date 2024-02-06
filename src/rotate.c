/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:57:18 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/30 16:05:10 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_size(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last = get_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
		rr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

void	ra(t_stack_node **stack_A)
{
	rotate(stack_A);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack_B)
{
	rotate(stack_B);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack_A, t_stack_node **stack_B)
{
	rotate(stack_A);
	rotate(stack_B);
	ft_printf("rr\n");
}
