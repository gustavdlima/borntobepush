#include "push_swap.h"

int	find_group_head(t_stacks *stacks, int group)
{
	t_doubly_list	*pivot_head;

	pivot_head = stacks->stack_a;
	while (1)
	{
		if (pivot_head->index <= stacks->max_values[group])
			return (pivot_head->index);
		pivot_head = pivot_head->next;
	}
	return (pivot_head->index);
}

int	find_group_tail(t_stacks *stacks, int group)
{
	t_doubly_list	*pivot_tail;

	pivot_tail = ft_doubly_lstlast(stacks->stack_a);
	while (1)
	{
		if (pivot_tail->index <= stacks->max_values[group])
			return (pivot_tail->index);
		pivot_tail = pivot_tail->prev;
	}
	return (0);
}
