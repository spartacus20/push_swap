#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	Stack	*st_a;
	Stack	*st_b;

	st_a = ft_create_stack();
	st_b = ft_create_stack();
	for (int i = 1; i <= 5; i++)
	{
		push(st_a, i);
	}
	ft_printf("Init a and b\n");
	for (int i = 0; i < 5; i++)
	{
		ft_printf("%d \t", st_a->items[i]);
		if (!isEmpty(st_b))
			ft_printf("%d", st_b->items[i]);
		ft_printf("\n");
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
	deleteStack(st_a);
	deleteStack(st_b);
	return (0);
}
