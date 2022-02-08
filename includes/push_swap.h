#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct s_doubly_list{
	int		content;
	struct s_doubly_list	*next;
	struct s_doubly_list	*prev;
}				t_doubly_list;

typedef struct s_stacks{
	t_doubly_list	*stack_a;
	t_doubly_list	*stack_b;
	int				stack_size;
}				t_stacks;

// -------------------------------------------- UTILS
// list_utils.c
t_doubly_list	*ft_doubly_lstlast(t_doubly_list *lst);
void			*ft_doubly_lstadd_front(t_doubly_list **lst, t_doubly_list *new);
void			ft_doubly_lstadd_back(t_doubly_list **lst, t_doubly_list *new);
t_doubly_list	*ft_doubly_lstnew(int content);

#endif
