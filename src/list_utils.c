#include "push_swap.h"

t_doubly_list	*ft_doubly_lstlast(t_doubly_list *lst);

void	ft_doubly_lstadd_back(t_doubly_list **lst, t_doubly_list *new)
{
	t_doubly_list	*aux;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		aux = ft_doubly_lstlast(*lst);
		aux->next = new;
		new->prev = aux;
		new->next = NULL;
	}
}

t_doubly_list	*ft_doubly_lstadd_front(t_doubly_list **lst, t_doubly_list *new)
{
	t_doubly_list	*aux;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		aux = *lst;
		aux->prev = new;
		new->next = aux;
		new->prev = NULL;
	}
}

t_doubly_list	*ft_doubly_lstlast(t_doubly_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

#include <stdio.h>
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
