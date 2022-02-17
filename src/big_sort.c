#include "push_swap.h"

static void	split_in_groups(t_stacks *stacks)
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
		if (stacks->stack_size % stacks->groups != 0
			&& counter == stacks->groups - 1)
			max_index = stacks->stack_size;
		stacks->max_values[counter] = max_index - 1;
		counter++;
		max_index += stacks->stack_size / stacks->groups;
	}
}

static void	sorting_groups(t_stacks *stacks)
{
	t_counts	count;

	initialise_counts(&count, stacks);
	while (stacks->stack_a)
	{
		if (stacks->stack_a->index <= stacks->max_values[count.small_group])
		{
			count.rbs = send_small_element_to_b(count.rbs, stacks);
			count.small_elements++;
		}
		else if (stacks->stack_a->index <= stacks->max_values[count.big_group]
			&& stacks->stack_a->index > stacks->max_values[count.big_group - 1])
		{
			pb(stacks);
			count.big_elements--;
			count.rbs++;
		}
		else
			count.rbs = rotate_stack_a(count.rbs, stacks);
		if (count.small_elements == stacks->max_values[count.small_group])
			count.small_group++;
		if (count.big_group > 0
			&& count.big_elements == stacks->max_values[count.big_group - 1])
			count.big_group--;
	}
}

static void	sort_and_push_back_to_a(t_stacks *stacks)
{
	int	index;

	index = stacks->stack_size;
	while (--index >= 0)
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
	return ;
}
