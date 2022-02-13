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
	int	count_small_groups;
	int	count_small_elements;
	int	count_big_groups;
	int	count_big_elements;
	int	count_rbs;
	// int	counter_elements;

	count_small_groups = 0;
	count_small_elements = 0;
	count_big_groups = stacks->groups - 1;
	count_big_elements = stacks->max_values[stacks->groups - 1];
	count_rbs = 0;
	// counter_elements = 0;

	while (stacks->stack_a)
	{
		if (count_small_elements == stacks->max_values[count_small_groups])
			count_small_groups++;
		if (count_big_groups > 0
			&& count_big_elements == stacks->max_values[count_big_groups - 1])
			count_big_groups--;
		if (stacks->stack_a->index <= stacks->max_values[count_small_groups])
		{
			while (count_rbs > 0)
			{
				rb(stacks, 1);
				count_rbs--;
			}
			pb(stacks);		// com certeza enviou um dos itens pequenos
			count_small_elements++;
		}
		else if (stacks->stack_a->index <= stacks->max_values[count_big_groups]
				&& stacks->stack_a->index > stacks->max_values[count_big_groups - 1])
		{
			pb(stacks);
			count_big_elements--;
			count_rbs++;
		}
		else
		{
			if (count_rbs > 0)
			{
				rr(stacks);
				count_rbs--;
			}
			else
				ra(stacks, 1);
		}
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
