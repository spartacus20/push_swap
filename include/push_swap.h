/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:55:20 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/05 18:29:45 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_SIZE 5
typedef struct stack
{
	int	top;
	int	size;
	int	items[MAX_SIZE];

}		Stack;

Stack	*ft_create_stack(void);
void	deleteStack(Stack *stack);
int		isEmpty(Stack *stack);
int		isFull(Stack *stack);
void	push(Stack *stack, int item);
int		pop(Stack *stack);
int		get_lenght(Stack *stack);

#endif
