#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_doubly_list *stack)
{
	printf("index:\tprev:\t\tcontent\t\tnext:\n---------------------------------------------\n");
	if (ft_doubly_lstsize(stack) == 1)
		printf("[0]\t[NULL]\t<-\t%i\t->\t[NULL]\n", stack->content);
	else
	{
		while (stack)
		{
			if (stack->prev == NULL)
				printf("[%i]\t[NULL]\t<-\t%i\t->\t%i\n", stack->index, stack->content, stack->next->content);
			else if (stack->next == NULL)
				printf("[%i]\t%i\t<-\t%i\t->\t[NULL]\n\n", stack->index, stack->prev->content, stack->content);
			else
				printf("[%i]\t%i\t<-\t%i\t->\t%i\n", stack->index, stack->prev->content, stack->content, stack->next->content);
			stack = stack->next;
		}
	}
}

void print_stacks(t_stacks *stacks)
{
	printf("stack_a : \n");
	print_stack(stacks->stack_a);
	printf("stack_b : \n");
	print_stack(stacks->stack_b);
}
