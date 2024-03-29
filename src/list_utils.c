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
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->prev = NULL;
		new->next = *lst;
		(*lst)->prev = new;
		(*lst) = new;
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
		element->index = 0;
		element->next = NULL;
		element->prev = NULL;
	}
	return (element);
}

int	ft_doubly_lstsize(t_doubly_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
