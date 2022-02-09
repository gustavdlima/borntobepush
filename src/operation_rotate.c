#include "push_swap.h"

/* first element becomes last, second becomes first, and so on*/
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

/* */
void	rb(t_stacks *stacks)
{
	return ;
}

/* */
void	rr(t_stacks *stacks)
{
	return ;
}
