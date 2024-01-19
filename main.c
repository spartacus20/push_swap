#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	resetStack(t_Stack **stack_a, t_Stack **stack_b, int n_items)
{
	if (*stack_a != NULL || *stack_b != NULL)
	{
		deleteStack(*stack_a);
		deleteStack(*stack_b);
		*stack_a = NULL;
		*stack_b = NULL;
	}
	*stack_a = ft_create_stack(n_items);
	*stack_b = ft_create_stack(n_items);
}

void	fillStackFromIntArray(t_Stack *stack, int *array, int size)
{
	if (size > 0 || array != NULL)
	{
		for (int i = 0; i < size; i++)
			push(stack, array[i]);
	}
}

void ft_print_list(char *msg, t_Stack *stack_a, t_Stack *stack_b)
{
    int max_length;

    printf("\n-----------------------------------------\n");
    printf("\t %s\n\n", msg);
    max_length = (stack_a->top > stack_b->top ? stack_a->top : stack_b->top) + 1;

    for (int i = max_length; i >= 0; i--)
    {
        if (i <= stack_a->top)
            printf("%d \t", stack_a->items[i]);
        else if (stack_b->top >= 0)  // Si hay elementos en el stack b, imprimir un espacio para alinear
            printf("  \t");

        if (i <= stack_b->top)
            printf("%d", stack_b->items[i]);
        printf("\n");
    }

    printf("_\t_\n");
    printf("a\tb\n");
}

int	main(int argv, char **args)
{
	t_Stack	*st_a;
	t_Stack	*st_b;
	int i;
	// int		arr_b[MAX_SIZE];
	st_a = ft_create_stack(argv - 1);
	st_b = ft_create_stack(argv - 1);
	printf("arv %d \n", argv);
	if(argv > 1){
		i = argv - 1;
		while(i > 0)
		{
			push(st_a, ft_atoi(args[i]));
			i--;
		}
	}
	ft_print_list("Init a and b", st_a, st_b);
	sa(st_a);
	ft_print_list("Exec sa", st_a, st_b);
	pb(st_a, st_b);
	pb(st_a, st_b);
	pb(st_a, st_b);
	ft_print_list("Exec pb pb pb", st_a, st_b);
	rotate_a(st_a);
	rotate_b(st_b);
	ft_print_list("Exec ra rb", st_a, st_b);
	reverse_rotate_a(st_a);
	reverse_rotate_b(st_b);
	ft_print_list("Exec rra rrb", st_a, st_b);
	sa(st_a);
	ft_print_list("Exec sa", st_a, st_b);
	pa(st_a, st_b);
	pa(st_a, st_b);
	pa(st_a, st_b);
	ft_print_list("Exec pa pa pa", st_a, st_b);
	deleteStack(st_a);
	deleteStack(st_b);
	return (0);
}
