#include "push_swap.h"

int	already_insert(t_doubly_list *stack, int num)
{
	while(stack)
	{
		if(stack->content == num)
		{
			free_stack(stack);
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}	