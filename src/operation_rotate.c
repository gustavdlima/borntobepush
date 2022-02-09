#include "push_swap.h"

/* rotate a - shift up all elements of stack a by 1.
	The first element becomes the last one.*/
void	ra(t_stacks *stacks)
{
	t_doubly_list	*temp;

	if (!stacks->stack_a->next)
		return ;
	temp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->prev = NULL;
	ft_doubly_lstadd_back(&(stacks->stack_a), temp);
	ft_putendl_fd("ra", 1);
	return ;
}

/* rotate b - shift up all elements of stack b by 1. The first element becomes
the last one. */
void	rb(t_stacks *stacks)
{
	t_doubly_list	*temp;

	if (stacks->stack_b->next == NULL)
		return ;
	temp = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	stacks->stack_b->prev = NULL;
	ft_doubly_lstadd_back(&(stacks->stack_b), temp);
	ft_putendl_fd("rb", 1);
	return ;
}

/* rotate a and rotate b at the same time. */
void	rr(t_stacks *stacks)
{
	return ;
}
