#include "push_swap.h"

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->stack_size = 0;
	stacks->groups = 0;
	return ;
}

int	is_sorted_asc(t_doubly_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

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
}
