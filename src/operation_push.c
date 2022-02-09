#include "push_swap.h"

/* push a - take the first element at the top of b and put it at
	the top of a. Do nothing if b is empty. */
void	pa(t_stacks *stacks)
{
	t_doubly_list	*first_element_stack_a;
	t_doubly_list	*old_stack_b;

	if (!stacks->stack_b)
		return ;
	first_element_stack_a = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	if (ft_doubly_lstsize(stacks->stack_a) > 0)
		stacks->stack_b->prev = NULL;
	first_element_stack_a->next = NULL;
	if (!stacks->stack_a)
	{
		stacks->stack_a = first_element_stack_a;
		stacks->stack_a->next = NULL;
		stacks->stack_a->prev = NULL;
	}
	else
	{
		old_stack_b = stacks->stack_a;
		stacks->stack_a = first_element_stack_a;
		stacks->stack_a->next = old_stack_b;
		old_stack_b->prev = stacks->stack_a;
	}
	ft_putendl_fd("pa", 1);
}

/* push b - take the first element at the top of a and put it at
	the top of b. Do nothing if a is empty. */
void	pb(t_stacks *stacks)
{
	t_doubly_list	*first_element_stack_a;
	t_doubly_list	*old_stack_b;

	if (!stacks->stack_a)
		return ;
	first_element_stack_a = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	if (ft_doubly_lstsize(stacks->stack_a) > 0)
		stacks->stack_a->prev = NULL;
	first_element_stack_a->next = NULL;
	if (!stacks->stack_b)
	{
		stacks->stack_b = first_element_stack_a;
		stacks->stack_b->next = NULL;
		stacks->stack_b->prev = NULL;
	}
	else
	{
		old_stack_b = stacks->stack_b;
		stacks->stack_b = first_element_stack_a;
		stacks->stack_b->next = old_stack_b;
		old_stack_b->prev = stacks->stack_b;
	}
	ft_putendl_fd("pb", 1);
}
