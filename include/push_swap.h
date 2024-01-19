/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:55:20 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/19 12:49:26 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define MAX_SIZE 5

typedef struct t_Stack
{
	int	top;
	int	size;
	int	*items;

}		t_Stack;

// Utils

t_Stack	*ft_create_stack(int n_items);
void	deleteStack(t_Stack *stack);
int		isEmpty(t_Stack *stack);
int		isFull(t_Stack *stack);
void	push(t_Stack *stack, int item);
int		pop(t_Stack *stack);
int		peek(t_Stack *stack);
int		get_lenght(t_Stack *stack);

// Rules

void	sa(t_Stack *stack_a);
void	sb(t_Stack *stack_b);
void	ss(t_Stack *stack_a, t_Stack *stack_b);
void	pa(t_Stack *stack_a, t_Stack *stack_b);
void	pb(t_Stack *stack_a, t_Stack *stack_b);
void	rotate_a(t_Stack *stack_a);
void	rotate_b(t_Stack *stack_b);
void	reverse_rotate_a(t_Stack *stack_a);
void	reverse_rotate_b(t_Stack *stack_b);
#endif
