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

int	calculate_ops_to_push(int index_size, t_stacks *stacks)
{
	int	count_operations;
	int	actual_stack_size;
	int	position;
	/* */
	actual_stack_size = ft_lstsize(stacks->stack_size);
	position = find_index(stacks, index_size);
	if (position < actual_stack_size / 2)
	{
		return (position);
	}
	else if (position > actual_stack_size / 2)
	{

	}

}
