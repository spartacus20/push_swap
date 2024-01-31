/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:58:54 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/31 16:59:17 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	free_arr(char **args)
{
	int	i;

	if (!args || !*args)
		return ;
	i = -1;
	while (args[i])
		free(args[i++]);
	free(args - 1);
}

void free_sort(t_sort *sort) {
    if (sort != NULL) {
        free(sort);
    }
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free_sort(current->sort);
		free(current);
		current = tmp;
	}

	*stack = NULL;

}

t_stack_node	*get_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	stack_append(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	node->sort = malloc(sizeof(t_sort));
	if (!node || !node->sort)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = get_last_node(*stack);
		last->next = node;
		node->prev = last;
	}
}

void	stack_init(t_stack_node **stack, char **args, int only_2)
{
	int	i;
	int	num;

	i = 0;
	while (args[i])
	{
		if (error_systax(args[i]))
			error_free(stack, args, only_2);
		num = ft_atoi(args[i]);
		if (error_num_repeated(*stack, num))
			error_free(stack, args, only_2);
		stack_append(stack, num);
		i++;
	}
	if (only_2)
		free_arr(args);
}
