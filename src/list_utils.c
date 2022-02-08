#include "push_swap.h"

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
