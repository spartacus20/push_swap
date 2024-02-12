/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:08:37 by jotomas-          #+#    #+#             */
/*   Updated: 2024/02/12 15:45:12 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:57:18 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/30 13:07:44 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_size(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	*stack = last;
	last->next->prev = last;
}

void	reverse_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
		rrr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

void	rra(t_stack_node **stack_A)
{
	reverse_rotate(stack_A);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_B)
{
	reverse_rotate(stack_B);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_A, t_stack_node **stack_B)
{
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
	ft_printf("rrr\n");
}
