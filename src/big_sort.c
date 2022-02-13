#include "push_swap.h"

/*
Função que divide em grupos e retorna o numero de grupos
*/
void	split_in_groups(t_stacks *stacks)
{
	int	max_index;
	int	counter;

	if (stacks->stack_size >= 500)
		stacks->groups = 12;
	else if (stacks->stack_size < 500 && stacks->stack_size > 5)
		stacks->groups = 5;
	if (stacks->stack_size % stacks->groups)
		stacks->groups++;
	stacks->max_values = (int *)malloc(sizeof(int) * stacks->groups);
	max_index = stacks->stack_size / stacks->groups;
	counter = 0;
	while (max_index <= stacks->stack_size)
	{
		if (stacks->stack_size % stacks->groups != 0 && counter == stacks->groups - 1)
			max_index = stacks->stack_size;
		stacks->max_values[counter] = max_index - 1;
		counter++;
		max_index += stacks->stack_size / stacks->groups;
	}
}

void	sorting_groups(t_stacks *stacks)
{
	int	counter_groups;
	int	counter_elements;

	counter_groups = 0;
	counter_elements = 0;
	while (counter_groups < stacks->groups)
	{
		/* find elements that we are looking for */
		while (counter_elements <= stacks->max_values[counter_groups])
		{
			choose_element_to_send_to_top(stacks, counter_groups);
			pb(stacks);
			counter_elements++;
		}
		counter_groups++;
	}
}

void	sort_and_push_back_to_a(t_stacks *stacks)
{
	int	index;

	index = stacks->stack_size;
	while(--index >= 0)
	{
		send_to_top_b(stacks, index);
		pa(stacks);
	}
	return ;
}

void	big_sort(t_stacks *stacks)
{
	split_in_groups(stacks);
	sorting_groups(stacks);
	sort_and_push_back_to_a(stacks);
}
