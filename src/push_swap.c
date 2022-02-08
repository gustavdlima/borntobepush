#include "push_swap.h"
#include <stdio.h>

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->stack_size = 0;
	printf("stacks initialised successfully\n");
	return ;
}

void	free_stack(t_doubly_list *stack)
{
	t_doubly_list	*aux;

	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	return ;
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free_stack(stacks->stack_a);
	if (stacks->stack_b)
		free_stack(stacks->stack_b);
	printf("stacks freed successfully\n");
}

int	is_sorted_asc(t_doubly_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
		{
			printf("stack not sorted in ascending order !\n");
			return (0);
		}
		stack = stack->next;
	}
	printf("stack sorted in ascending order !\n");
	return (1);
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
	// }	
	// free(split_args);
	return (1);
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
				// sort(&stacks);
			}
		}
	// lembrar de dar o free_stacks depois de encerrar o algoritmo
	// free_stacks(stacks);
	}
	return 0;
}
