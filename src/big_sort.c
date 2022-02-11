#include "push_swap.h"

/*
Função que divide em grupos e retorna o numero de grupos
*/
void	split_in_groups(t_stacks *stacks)
{
	int	max_index;
	int	counter;

	stacks->groups = ft_sqrt(stacks->stack_size);
	if (stacks->stack_size % stacks->groups)
		stacks->groups++;
	stacks->max_values = (int *)malloc(sizeof(int) * stacks->groups);
	max_index = stacks->stack_size / stacks->groups;
	counter = 0;
	while (max_index <= stacks->stack_size)
	{
		if (stacks->stack_size % stacks->groups != 0 && counter == stacks->groups - 1)
			max_index = stacks->stack_size;
		stacks->max_values[counter] = max_index - 1;
		counter++;
		max_index += stacks->stack_size / stacks->groups;
	}
}

void	sorting_groups(t_stacks *stacks)
{
	int	counter_groups;
	int	counter_elements;

	counter_groups = 0;
	counter_elements = 0;
	while (counter_groups < stacks->groups)
	{
		/* find elements that we are looking for */
		while (counter_elements <= stacks->max_values[counter_groups])
		{
/*
[ ] [ ] [ ] [18 19 20 21 22 23] [24 25 26 27 28 29 30]
		// encontra o número do grupo mais próximo possível
		// critério de desempate: o menor índice !!!!!!!!!!!!!!
		// 19 26 [6] 3 29 27 11 8 12 22 10 1 14 16 9 21 15 24 25 20 0 7 13 18 17 4 2 30 23 [5] 28
		26 29 27 24 25 30 28

		[19] [23] [18] [20] [21] [22] [12] [14] [16] [15] [17] [13] [7] [9] [10] [8] [11] [6] [3] [1] [0] [4] [2] [5]

*/
			int index_head;
			int index_tail;
			int ops_to_push_head;
			int ops_to_push_tail;
			index_head = find_group_head(stacks, counter_groups);
			index_tail = find_group_tail(stacks, counter_groups);
			ops_to_push_head = calculate_ops_to_push(index_head);
			ops_to_push_tail = calculate_ops_to_push(index_tail);
			calculate_ops_to_push()
			{
				int	count_operations;
				send_to_top_b
			}
			if (ops_to_push_head > ops_to_push_tail)
			{
					//
			}
			else if (ops_to_push_head < ops_to_push_tail)
			{
					//
			}
			else
			{
				if (index_head < index_tail)
					send_to_top_a(index_head);
				else
					send_to_top_a(index_tail);
			}
			pb(stacks);
		}
		counter_groups++;
	}
}

/*
Função auxiliar que escaneia a stack_a verificando se ainda restam itens
do grupo atual
*/

// void	parse_to_push(t_stacks *stacks, int groups)
// {
// 	int	i;

// 	i = 0;
// 	while (i < groups)
// 	{
// 		if ()
// 		{
// 			//push a_to_b;
// 		}
// 		i++;
// 	}
// }

//Dividir a stack em grupos. Como será feita essa divisão?
//Definir o índice máximo de cada grupo o limitador na hora de separar
//
void	sort_and_push_back_to_a(t_stacks *stacks)
{
	int	index;

	index = stacks->stack_size;
	while(--index >= 0)
	{
		send_to_top_b(stacks, index);
		pa(stacks);
	}
	return ;
}

void	big_sort(t_stacks *stacks)
{
	split_in_groups(stacks);
	sorting_groups(stacks);
	sort_and_push_back_to_a(stacks);
}
