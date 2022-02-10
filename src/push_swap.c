#include "push_swap.h"

void	push_swap(t_stacks *stacks)
{
	print_stacks(stacks);
	sort(stacks);
	// print_stacks(stacks);
	print_stacks(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc >= 2)
	{
		if (validate_input(&stacks, argc, argv) == 1)
		{
			if (!is_sorted_asc(stacks.stack_a))
			{
				push_swap(&stacks);
			}
			free_stacks(&stacks);
		}
	}
	return 0;
}
