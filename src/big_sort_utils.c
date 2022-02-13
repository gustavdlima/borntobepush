#include "push_swap.h"

// int	find_group_head(t_stacks *stacks, int group)
// {
// 	t_doubly_list	*pivot_head;

// 	pivot_head = stacks->stack_a;
// 	while (1)
// 	{
// 		if (pivot_head->index <= stacks->max_values[group])
// 			return (pivot_head->index);
// 		pivot_head = pivot_head->next;
// 	}
// 	return (pivot_head->index);
// }

// int	find_group_tail(t_stacks *stacks, int group)
// {
// 	t_doubly_list	*pivot_tail;

// 	pivot_tail = ft_doubly_lstlast(stacks->stack_a);
// 	while (1)
// 	{
// 		if (pivot_tail->index <= stacks->max_values[group])
// 			return (pivot_tail->index);
// 		pivot_tail = pivot_tail->prev;
// 	}
// 	return (0);
// }

// int	rotate_to_top(int count, t_stacks *stacks, int count_backwards)
// {
// 	int	decrement;

// 	decrement = 0;
// 	while (count--)
// 	{
// 		if (stacks->stack_a->index <= stacks->max_values[count_backwards]
// 			&& stacks->stack_a->index > stacks->max_values[count_backwards - 1])
// 		{
// 			pb(stacks);
// 			rr(stacks);
// 			decrement++;
// 		}
// 		else
// 			ra(stacks, 1);
// 	}
// 	return (decrement);
// }

// int	rev_rotate_to_top(int count, t_stacks *stacks, int count_backwards)
// {
// 	int	decrement;

// 	decrement = 0;
// 	while (count--)
// 	{
// 		if (stacks->stack_a->index <= stacks->max_values[count_backwards]
// 			&& stacks->stack_a->index > stacks->max_values[count_backwards - 1])
// 		{
// 			pb(stacks);
// 			rb(stacks, 1);
// 			decrement++;
// 		}
// 		else
// 			rra(stacks, 1);
// 	}
// 	return (decrement);
// }

// void	choose_element_to_send_to_top(t_stacks *stacks, int count_groups)
// {
// 	int	index_head;
// 	int	index_tail;
// 	int	ops_to_push_head;
// 	int	ops_to_push_tail;
// 	int	count_back = stacks->groups - 1;

// 	// refatorar esse if pra reduzir linha aqui pra conseguir incluir um count
// 	// backwards que em todo rotate up/down vai fazer o check se dá pra mandar
// 	// o elemento atual pra stack_b
// 	index_head = find_group_head(stacks, count_groups);
// 	index_tail = find_group_tail(stacks, count_groups);
// 	ops_to_push_head = find_index(stacks->stack_a, index_head);
// 	ops_to_push_tail = ft_doubly_lstsize(stacks->stack_a)
// 		- find_index(stacks->stack_a, index_tail);
// 	if (ops_to_push_head > ops_to_push_tail)
// 		count_back -= rev_rotate_to_top(ops_to_push_tail, stacks, count_back);
// 	else if (ops_to_push_head < ops_to_push_tail)
// 		count_back -= rotate_to_top(ops_to_push_head, stacks, count_back);
// 	else
// 	{
// 		if (index_head > index_tail)
// 			count_back -= rev_rotate_to_top(ops_to_push_tail, stacks, count_back);
// 		else if (index_head < index_tail)
// 			count_back -= rotate_to_top(ops_to_push_head, stacks, count_back);
// 		else
// 			send_to_top_a(stacks, index_head);
// 	}
// }
