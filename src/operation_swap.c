#include "push_swap.h"

/* sa : swap a - swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements).*/
void	sa(t_stacks *stacks, int flag)
{
	t_doubly_list	*new_second;
	t_doubly_list	*third;

	if (ft_doubly_lstsize(stacks->stack_a) < 2)
		return ;
	new_second = stacks->stack_a;
	third = stacks->stack_a->next->next;
	stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->prev = NULL;
	stacks->stack_a->next = new_second;
	new_second->next = third;
	new_second->prev = stacks->stack_a;
	if (third)
		third->prev = stacks->stack_a->next;
	if (flag == 1)
		ft_putendl_fd("sa", 1);
}

/* sb : swap b - swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements).*/
void	sb(t_stacks *stacks, int flag)
{
	t_doubly_list	*new_second;
	t_doubly_list	*third;

	if (ft_doubly_lstsize(stacks->stack_b) < 2)
		return ;
	new_second = stacks->stack_b;
	third = stacks->stack_b->next->next;
	stacks->stack_b = stacks->stack_b->next;
	stacks->stack_b->prev = NULL;
	new_second->prev = stacks->stack_b;
	new_second->next = third;
	stacks->stack_b->next = new_second;
	if (third)
		third->prev = new_second;
	if (flag == 1)
		ft_putendl_fd("sb", 1);
}

/* ss: sa and sb at the same time. */
void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	ft_putendl_fd("ss", 1);
}
