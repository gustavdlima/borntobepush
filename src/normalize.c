#include "push_swap.h"

void	normalize(t_stacks *stacks)
{
	t_doubly_list	*pivot;
	t_doubly_list	*pivot_aux;

	pivot = stacks->stack_a;
	while (pivot->next)
	{
		pivot_aux = pivot->next;
		while (pivot_aux)
		{
			if (pivot->content > pivot_aux->content)
				pivot->index++;
			else
				pivot_aux->index++;
			pivot_aux = pivot_aux->next;
		}
		pivot = pivot->next;
	}
	return ;
}
