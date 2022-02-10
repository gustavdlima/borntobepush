#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	if (ft_doubly_lstsize(stacks->stack_a) <= 3)
	{
		sort_three(stacks);
	}
	if (ft_doubly_lstsize(stacks->stack_a) > 3
			&& ft_doubly_lstsize(stacks->stack_a) <= 5)
	{
		sort_five(stacks);
	}
}
void	sort_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	if (ft_doubly_lstsize(stacks->stack_a) == 2
		&& !is_sorted_asc(stacks->stack_a))
	{
		sa(stacks, 1);
		return ;
	}
	first = stacks->stack_a->index;
	second = stacks->stack_a->next->index;
	third = stacks->stack_a->next->next->index;
	if ((first > second && second > third && third < first)
			|| (first < second && second > third && third > first)
			|| (first > second && second < third && third > first))
		sa(stacks, 1);
	first = stacks->stack_a->index;
	second = stacks->stack_a->next->index;
	third = stacks->stack_a->next->next->index;
	if (first < second && second > third && third < first)
		rra(stacks, 1);
	if (first > second && second < third && second < first)
		ra(stacks, 1);
}

void	sort_five(t_stacks *stacks)
{
	t_doubly_list	*aux;

	aux = stacks->stack_a;
	while (!is_sorted_asc(stacks->stack_a))
	{
		while (ft_doubly_lstsize(stacks->stack_a) != 3)
		{
			send_to_top(stacks, 0);
			pb(stacks);
			send_to_top(stacks, 1);
			pb(stacks);
		}
		sort_three(stacks);
		pb(stacks);
		pb(stacks);
	}
}


void	send_to_top(t_stacks *stacks, int index)
{
	int	position;

	position = find_index(stacks, index);
	if (position <= ft_doubly_lstsize(stacks->stack_a) / 2)
	{
		while (stacks->stack_a->index != index)
		{
			ra(stacks, 1);
		}
	}
	else
	{
		while (stacks->stack_a->index != index)
		{
			rra(stacks, 1);
		}
	}
}

int	find_index(t_stacks *stacks, int index_size)
{
	int	i;

	i = 0;
	while (stacks->stack_a)
	{
		if (stacks->stack_a->index == index_size)
			return (i);
		stacks->stack_a = stacks->stack_a->next;
		i++;
	}
}
