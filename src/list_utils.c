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

void	ft_doubly_lstadd_front(t_doubly_list **lst, t_doubly_list *new)
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

t_doubly_list	*ft_doubly_lstnew(int content)
{
	t_doubly_list	*element;

	element = (t_doubly_list *) malloc(sizeof(t_doubly_list));
	if (element)
	{
		element->content = content;
		element->next = NULL;
		element->prev = NULL;
	}
	return (element);
}
