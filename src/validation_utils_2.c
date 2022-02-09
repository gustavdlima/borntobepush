#include "push_swap.h"

int	has_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while(i < argc)
	{
		j += i;
		while(j < argc)
		{
			if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	already_insert(t_doubly_list *stack, int num)
{
	while(stack)
	{
		if(stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}	