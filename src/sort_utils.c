#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	if (nb <= 0)
		return (0);
	while (n <= 46340)
	{
		if (n * n == nb)
			return (n);
		else if (n * n > nb)
			return (n - 1);
		n++;
	}
	return (0);
}

int	rotate_stack_a(int count_rbs, t_stacks *stacks)
{
	if (count_rbs > 0)
	{
		rr(stacks);
		count_rbs--;
	}
	else
		ra(stacks, 1);
	return (count_rbs);
}

int	send_small_element_to_b(int count_rbs, t_stacks *stacks)
{
	while (count_rbs > 0)
	{
		rb(stacks, 1);
		count_rbs--;
	}
	pb(stacks);
	return (count_rbs);
}
