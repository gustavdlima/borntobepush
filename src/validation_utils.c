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
	int			argv_num;
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
		if(!validate_is_range_int(argc, argv) || !validate_is_all_digit(argc, argv))
			return (printf(BOLDRED"Numeros maiores que INT ou contem strings\n"RESET));
		initialise(stacks);
		i = 1;
		while (argv[i])
		{
			argv_num = ft_atoi(argv[i]);
			if(check_for_duplicate(stacks->stack_a, argv_num))
				return (printf(BOLDRED"Existem Duplicatas"RESET));
			ft_doubly_lstadd_back(&(stacks->stack_a), ft_doubly_lstnew(argv_num));
			i++;
		}
		// i = 10;
		// while (i < 15)
		// {
		// 	ft_doubly_lstadd_back(&(stacks->stack_b), ft_doubly_lstnew(i));
		// 	i++;
		// }

	// }
	// free(split_args);
	return (1);
}

int	validate_is_range_int(int argc, char *argv[])
{
	int			i;
	long int	argv_num;

	i = 1;
	while (i < argc)
	{
		argv_num = ft_atoli(argv[i]);
		if(argv_num > INT_MAX || argv_num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	is_all_digit(const char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		i++;
	while (i < ft_strlen(str))
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_is_all_digit(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if(!is_all_digit(argv[i]))
			return(0);
		i++;
	}
	return (1);
}
