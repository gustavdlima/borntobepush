
#include "push_swap.h"

/* sa : swap a - swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements).*/
void	sa(t_stacks *stacks)
{
	t_doubly_list	new_first;
	t_doubly_list	new_second;

	new_first = *(stacks->stack_a->next);
	new_first.prev = NULL;
	new_first.next = stacks->stack_a;
	new_second = *(stacks->stack_a);
	new_second.prev = &new_first;
	new_second.next = stacks->stack_a->next->next;
	stacks->stack_a = &new_first;
	stacks->stack_a->next = &new_second;
	stacks->stack_a->next->next->prev = stacks->stack_a->next->next;
	// new_second = stacks->stack_a;
	// new_first = stacks->stack_a->next;
	// stacks->stack_a->next = new_first->next;
	// stacks->stack_a->next->prev = new_second;
	// stacks->stack_a->prev = new_first;
	// new_first->next = stacks->stack_a;
	// new_first->prev = NULL;
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
