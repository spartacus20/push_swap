/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:45:36 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/19 13:47:02 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	sa(t_Stack *stack_a)
{
	int	tmp;

	if (get_lenght(stack_a) > 1)
	{
		tmp = stack_a->items[stack_a->top];
		stack_a->items[stack_a->top] = stack_a->items[stack_a->top - 1];
		stack_a->items[stack_a->top - 1] = tmp;
	}
}

void	sb(t_Stack *stack_b)
{
	int	tmp;

	if (get_lenght(stack_b) > 1)
	{
		tmp = stack_b->items[stack_b->top];
		stack_b->items[stack_b->top] = stack_b->items[stack_b->top - 1];
		stack_b->items[stack_b->top - 1] = tmp;
	}
}

void	ss(t_Stack *stack_a, t_Stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_Stack *stack_a, t_Stack *stack_b)
{
	int	item;

	item = pop(stack_b);
	if (item != -1)
	{
		push(stack_a, item);
	}
}

void	pb(t_Stack *stack_a, t_Stack *stack_b)
{
	int	item;

	item = pop(stack_a);
	if (item != -1)
	{
		push(stack_b, item);
	}
}
void	rotate_a(t_Stack *stack_a)
{
	int	i;
	int	first;

	if (get_lenght(stack_a) < 1)
		return ;
	first = stack_a->items[stack_a->top];
	i = stack_a->top;
	while (i > 0)
	{
		stack_a->items[i] = stack_a->items[i - 1];
		i--;
	}
	stack_a->items[0] = first;
}
void	rotate_b(t_Stack *stack_b)
{
	int	i;
	int	first;

	if (get_lenght(stack_b) < 1)
		return ;
	first = stack_b->items[stack_b->top];
	i = stack_b->top;
	while (i > 0)
	{
		stack_b->items[i] = stack_b->items[i - 1];
		i--;
	}
	stack_b->items[0] = first;
}
void	reverse_rotate_a(t_Stack *stack_a)
{
	int	i;
	int	last;

	if (get_lenght(stack_a) < 1)
		return ;
	last = stack_a->items[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->items[i] = stack_a->items[i + 1];
		i++;
	}
	stack_a->items[stack_a->top] = last;
}
void	reverse_rotate_b(t_Stack *stack_b)
{
	int	i;
	int	last;

	if (get_lenght(stack_b) < 1)
		return ;
	last = stack_b->items[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->items[i] = stack_b->items[i + 1];
		i++;
	}
	stack_b->items[stack_b->top] = last;
}
