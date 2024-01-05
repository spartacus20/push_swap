/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:14:44 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/05 18:31:37 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

Stack	*ft_create_stack(void)
{
	Stack	*stack;

	stack = (Stack *)malloc(sizeof(Stack));
	if (!stack)
		return (NULL);
	stack->top = -1;
	stack->size = 0;
	return (stack);
}

void	deleteStack(Stack *stack)
{
	while (stack->top != -1)
		pop(stack);
	free(stack);
}

int	isFull(Stack *stack)
{
	if (stack->top == MAX_SIZE - 1)
		return (1);
	else
		return (0);
}

int	isEmpty(Stack *stack)
{
	if (stack->top == -1)
		return (1);
	else
		return (0);
}

void	push(Stack *stack, int item)
{
	if (isFull(stack))
		ft_printf("Overflow Error");
	else
	{
		stack->items[++stack->top] = item;
		stack->size++;
	}
}

int	pop(Stack *stack)
{
	int	items;

	if (isEmpty(stack))
	{
		ft_printf("Stack is empty");
		return (-1);
	}
	stack->size--;
	items = stack->items[--stack->top];
	return (items);
}

int	get_lenght(Stack *stack)
{
	return (stack->size);
}

int	peek(Stack *stack)
{
	if (!isEmpty(stack))
		return (stack->top);
	return -1;
}
