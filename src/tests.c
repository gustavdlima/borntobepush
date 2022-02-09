#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_doubly_list *stack)
{
	while (stack)
	{
		if (stack->prev == NULL)
			printf("\nprev ->    [NULL]\n");
		else
			printf("prev ->    [%d]\n", stack->prev->content);
		printf("content -> [%d]\n", stack->content);
		if (stack->next == NULL)
			printf("next ->    [NULL]\n\n");
		else
			printf("next ->    [%d]\n\n", stack->next->content);
		stack = stack->next;
	}
}

// int main()
// {
// 	t_doubly_list element1;

// 	element1.content = 1;
// 	element1.prev = NULL;
// 	element1.next = NULL;
// 	printf("element1: %p\n", &element1);
// 	printf("element1.prev: %p\n", element1.prev);
// 	printf("element1.next: %p\n\n", element1.next);

// 	t_doubly_list element2;

// 	element2.content = 2;
// 	element2.prev = NULL;
// 	element2.next = NULL;
// 	printf("element2: %p\n", &element2);
// 	printf("element2.prev: %p\n", element2.prev);
// 	printf("element2.next: %p\n\n", element2.next);

// 	element1.next = &element2;
// 	element2.prev = &element1;
// 	printf("element2: %p\n", &element2);
// 	printf("element2.prev: %p\n", element2.prev);
// 	printf("element2.next: %p\n\n", element2.next);

// 	printf("element1: %p\n", &element1);
// 	printf("element1.prev: %p\n", element1.prev);
// 	printf("element1.next: %p\n", element1.next);

// 	printf("ft_last: %p\n", ft_doubly_lstlast(&element1));

// }
