#include "push_swap.h"

static int	validate_is_range_int(int argc, char *argv[])
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

static int	is_all_digit(const char *str)
{
	size_t	i;

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

static int	validate_is_all_digit(int argc, char *argv[])
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

static int	check_for_duplicate(t_doubly_list *stack, int num)
{
	while(stack)
	{
		if(stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	validate_input(t_stacks *stacks, int argc, char *argv[])
{
	int			i;
	int			argv_num;

	if(!validate_is_range_int(argc, argv) || !validate_is_all_digit(argc, argv))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	initialise(stacks);
	i = 1;
	while (argv[i])
	{
		argv_num = ft_atoi(argv[i]);
		if(check_for_duplicate(stacks->stack_a, argv_num))
		{
			ft_putendl_fd("Error", 1);
			free_stacks(stacks);
			return (0);
		}
		ft_doubly_lstadd_back(&(stacks->stack_a), ft_doubly_lstnew(argv_num));
		i++;
	}
	stacks->stack_size = i - 1;
	normalize(stacks);
	return (1);
}
