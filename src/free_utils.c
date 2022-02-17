#include "push_swap.h"

void	free_stack(t_doubly_list *stack)
{
	t_doubly_list	*aux;

	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	return ;
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free_stack(stacks->stack_a);
	if (stacks->stack_b)
		free_stack(stacks->stack_b);
	if (stacks->max_values)
		free(stacks->max_values);
}
