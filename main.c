/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:55:49 by jotomas-          #+#    #+#             */
/*   Updated: 2024/02/12 16:04:38 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	check_args(int argv)
{
	if (argv == 2)
		return (1);
	return (0);
}

int	main(int argv, char **args)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argv == 1 || (argv == 2 && !args[1][0]))
		return (1);
	else if (argv == 2)
		args = ft_split(args[1], SPACE);
	stack_init(&stack_a, args + 1, check_args(argv));
	if (!stack_is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) == 3)
			sort_three_nb(&stack_a);
		else
			sort_big_nb(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
