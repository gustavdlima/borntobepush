/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:58:29 by gusalves          #+#    #+#             */
/*   Updated: 2022/02/13 22:58:29 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define RESET   "\033[0m"		 /* Reset color to default */
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

# include "libft.h"
# include <stdio.h>

typedef struct s_doubly_list{
	int						content;
	int						index;
	struct s_doubly_list	*next;
	struct s_doubly_list	*prev;
}				t_doubly_list;

typedef struct s_stacks{
	t_doubly_list	*stack_a;
	t_doubly_list	*stack_b;
	int				*max_values;
	int				groups;
	int				stack_size;
}				t_stacks;

typedef struct s_counts{
	int	small_group;
	int	small_elements;
	int	big_group;
	int	big_elements;
	int	rbs;
}				t_counts;

// -------------------------------------------- UTILS
// list_utils.c
t_doubly_list	*ft_doubly_lstlast(t_doubly_list *lst);
void			ft_doubly_lstadd_front(t_doubly_list **lst, t_doubly_list *new);
void			ft_doubly_lstadd_back(t_doubly_list **lst, t_doubly_list *new);
t_doubly_list	*ft_doubly_lstnew(int content);
int				ft_doubly_lstsize(t_doubly_list *lst);

// normalize.c
void			normalize(t_stacks *stacks);

// push_swap_utils.c
int				is_sorted_asc(t_doubly_list *stack);

// free_utils.c
void			free_stack(t_doubly_list *stack);
void			free_stacks(t_stacks *stacks);

// -------------------------------------------- VALIDATIONS
// validation_utils.c
int				validate_input(t_stacks *stacks, int argc, char *argv[]);

// --------------------------------------------  SORT UTILS
// sort.c
void			sort_three(t_stacks *stacks);
void			sort_five(t_stacks *stacks);
int				find_index(t_doubly_list *stack, int index_size);
void			send_to_top_a(t_stacks *stacks, int index);
void			send_to_top_b(t_stacks *stacks, int index);

// sort_utils.c
int				ft_sqrt(int nb);
int				rotate_stack_a(int count_rbs, t_stacks *stacks);
int				send_small_element_to_b(int count_rbs, t_stacks *stacks);

// initialise_utils.c
void			initialise_counts(t_counts *counts, t_stacks *stacks);
void			initialise(t_stacks *stacks);

// --------------------------------------------  BIG SORT
// big_sort.c
void			big_sort(t_stacks *stacks);

// -------------------------------------------- OPERATION SWAP
// operations_swap.c
void			sa(t_stacks *stacks, int flag);
void			sb(t_stacks *stacks, int flag);
void			ss(t_stacks *stacks);

// operation_push.c
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);

// operation_rotate.c
void			ra(t_stacks *stacks, int flag);
void			rb(t_stacks *stacks, int flag);
void			rr(t_stacks *stacks);

// operation_reverse_rotate.c
void			rra(t_stacks *stacks, int flag);
void			rrb(t_stacks *stacks, int flag);
void			rrr(t_stacks *stacks);

// -------------------------------------------- TESTS
void			print_stack(t_doubly_list *stack);
void			print_stacks(t_stacks *stacks);

#endif
