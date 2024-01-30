/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:39:12 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/30 12:58:44 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_stack_node **stack)
{
	int	len;

	len = stack_size(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **stack_A)
{
	swap(stack_A);
	ft_printf("sa\n");
}

void	sb(t_stack_node **stack_B)
{
	swap(stack_B);
	ft_printf("sb\n");
}

void	ss(t_stack_node **stack_A, t_stack_node **stack_B)
{
	swap(stack_A);
	swap(stack_B);
	ft_printf("ss\n");
}
