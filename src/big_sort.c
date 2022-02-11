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
			if (stacks->stack_a->index <= stacks->max_values[counter_groups])
			{
				pb(stacks);
				counter_elements++;
			}
			else
				ra(stacks, 1);
		}
		print_stack(stacks->stack_b);
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

void	big_sort(t_stacks *stacks)
{
	split_in_groups(stacks);
	sorting_groups(stacks);
}
