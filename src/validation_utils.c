#include "push_swap.h"

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->stack_size = 0;
	printf("stacks initialised successfully\n");
	return ;
}

int	validate_input(t_stacks *stacks, int argc, char *argv[])
{
	int			i;
	// char	**split_args;

	printf("... validating input\n");
	// if (argc == 2 && *argv[1] != "\"")
	// 	return (0);
	// if (argc == 2 && *argv[1] == "\"")
	// {
	// 	split_args = ft_split(argv[1], ' ');
	// }
	// if (argv[i] não for numérico)
	// 	return (0);
	// if (argv[i] não for int (maior que INT_MAX e menor que INT_MIN))
	// 	return (0);
	// else
	// {
		// monta a stack a;
		initialise(stacks);
		i = 1;
		while (argv[i])
		{
			ft_doubly_lstadd_back(&(stacks->stack_a), ft_doubly_lstnew(ft_atoi(argv[i])));
			i++;
		}
		// i = 10;
		// while (i < 12)
		// {
		// 	ft_doubly_lstadd_back(&(stacks->stack_b), ft_doubly_lstnew(i));
		// 	i++;
		// }

	// }
	// free(split_args);
	return (1);
}
