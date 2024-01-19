/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:14:44 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/19 12:49:59 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_Stack	*ft_create_stack(int n_items)
{
	t_Stack	*stack;

	stack = (t_Stack *)malloc(sizeof(t_Stack));
	if (!stack)
		return (NULL);
	stack->top = -1;
	stack->size = 0;
	stack->items = malloc(sizeof(int) * n_items + 1);
	if (!stack->items)
		return (NULL);
	return (stack);
}

void	deleteStack(t_Stack *stack)
{
	while (stack->top != -1)
		pop(stack);
	free(stack);
}

int	isFull(t_Stack *stack)
{
	if (stack->top == 6 - 1)
		return (1);
	else
		return (0);
}

int	isEmpty(t_Stack *stack)
{
	if (stack->top == -1)
		return (1);
	else
		return (0);
}

void	push(t_Stack *stack, int item)
{
	if (isFull(stack))
		ft_printf("Overflow Error");
	else
	{
		stack->items[++stack->top] = item;
		stack->size++;
	}
}
//Delete item from the end of the list
// Example if i have: 1, 2, 3, 4
// the 4 will be removed by the top.
int	pop(t_Stack *stack)
{
	int	items;

	if (isEmpty(stack))
	{
		ft_printf("t_Stack is empty");
		return (-1);
	}
	stack->size--;
	items = stack->items[stack->top];
	stack->top--;
	return (items);
}



int	get_lenght(t_Stack *stack)
{
	return (stack->size);
}

int	peek(t_Stack *stack)
{
	if (!isEmpty(stack))
		return (stack->items[stack->top]);
	return (-1);
}
