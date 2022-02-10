#include "push_swap.h"

void	sort(t_stacks *stacks)
{
	if (ft_doubly_lstsize(stacks->stack_a) == 3)
	{
		sort_three(stacks);
	}
}

void	sort_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->stack_a->content;
	second = stacks->stack_a->next->content;
	third = stacks->stack_a->next->next->content;
	if ((first > second && second > third && third < first)
			|| (first < second && second > third && third > first)
			|| (first > second && second < third && third > first))
		sa(stacks, 1);
	first = stacks->stack_a->content;
	second = stacks->stack_a->next->content;
	third = stacks->stack_a->next->next->content;
	if (first < second && second > third && third < first)
		rra(stacks, 1);
	if (first > second && second < third && second < first)
		ra(stacks, 1);
}
