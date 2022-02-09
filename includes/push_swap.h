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
void			ft_doubly_lstadd_front(t_doubly_list **lst, t_doubly_list *new);
void			ft_doubly_lstadd_back(t_doubly_list **lst, t_doubly_list *new);
t_doubly_list	*ft_doubly_lstnew(int content);
int				ft_doubly_lstsize(t_doubly_list *lst);

// push swap utils
int		is_sorted_asc(t_doubly_list *stack);
void	initialise(t_stacks *stacks);
void	free_stack(t_doubly_list *stack);
void	free_stacks(t_stacks *stacks);

// -------------------------------------------- VALIDATIONS
// validation_utils.c
int	validate_input(t_stacks *stacks, int argc, char *argv[]);

// -------------------------------------------- PUSH SWAP
// push_swap.c
void	push_swap(t_stacks *stacks);

// -------------------------------------------- OPERATION SWAP
// operations_swap.c
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

// -------------------------------------------- PRA DELETAR DEPOIS
void	print_stack(t_doubly_list *stack);
void	print_stacks(t_stacks *stacks);

#endif
