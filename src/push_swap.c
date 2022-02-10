#include "push_swap.h"

void	push_swap(t_stacks *stacks)
{
	print_stacks(stacks);
	pb(stacks);
	pb(stacks);
	pb(stacks);
	pb(stacks);
	print_stacks(stacks);
	rb(stacks, 1);
	rb(stacks, 1);
	ss(stacks);
	print_stacks(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc >= 2)
	{
		if (validate_input(&stacks, argc, argv) == 1)
		{
			printf("input is valid ! !\n");
			if (!is_sorted_asc(stacks.stack_a))
			{
				printf("colocar a função sort aqui!\n");
				push_swap(&stacks);
			}
		}
	// lembrar de dar o free_stacks depois de encerrar o algoritmo
	// free_stacks(stacks);
	}
	return 0;
}
