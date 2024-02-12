/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:11:25 by jotomas-          #+#    #+#             */
/*   Updated: 2024/02/12 16:14:11 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	error_free(t_stack_node **stack, char **args, int only_2)
{
	free_stack(stack);
	if (only_2)
		free_arr(args);
	ft_printf("Error\n");
	exit(1);
}

int	error_systax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0'
				&& *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0'
			&& str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_num_repeated(t_stack_node *stack, int nbr)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
