
#include "push_swap.h"

/* sa : swap a - swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements).*/
void	sa(t_stacks *stacks)
{
	t_doubly_list	*new_second;
	t_doubly_list	*third;

	new_second = stacks->stack_a;
	third = stacks->stack_a->next->next;
	stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->prev = NULL;
	stacks->stack_a->next = new_second;
	new_second->next = third;
	new_second->prev = stacks->stack_a;
	if (third)
		third->prev = stacks->stack_a->next;
	ft_putendl_fd("\n--------- sa operation ---------\n", 1);
}
// 1
// 4 new first
// 3

/* sb : swap b - swap the first 2 elements at the top of stack b.
    Do nothing if there is only one or no elements).*/
void	sb(t_stacks *stacks)
{}

/* ss: sa and sb at the same time. */
void	ss(t_stacks *stacks)
{}
