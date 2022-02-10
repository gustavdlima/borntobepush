#include "push_swap.h"

void	rra(t_stacks *stacks, int flag)
{
	t_doubly_list	*last_element;

	if (stacks->stack_a->next == NULL)
		return ;
	last_element = ft_doubly_lstlast(stacks->stack_a);
	last_element->prev->next = NULL;
	last_element->prev = NULL;
	ft_doubly_lstadd_front(&(stacks->stack_a), last_element);
	if (flag == 1)
		ft_putendl_fd("rra", 1);
	return ;
}

void	rrb(t_stacks *stacks, int flag)
{
	t_doubly_list	*last_element;

	if (stacks->stack_b->next == NULL)
		return ;
	last_element = ft_doubly_lstlast(stacks->stack_b);
	last_element->prev->next = NULL;
	last_element->prev = NULL;
	ft_doubly_lstadd_front(&(stacks->stack_b), last_element);
	if (flag == 1)
		ft_putendl_fd("rrb", 1);
	return ;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	ft_putendl_fd("rrr", 1);
	return ;
}
