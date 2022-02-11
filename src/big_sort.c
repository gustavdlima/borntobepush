#include "push_swap.h"

/*
Função que divide em grupos e retorna o numero de grupos
*/
int	split_in_groups(t_stacks *stacks)
{
	int	groups;
	int	max_index;
	int	counter;

	groups = ft_sqrt(stacks->stack_size);
	if (stacks->stack_size % groups)
		groups++;
	stacks->max_values = (int *)malloc(sizeof(int) * groups);
	max_index = stacks->stack_size / groups;
	counter = 0;
	while (max_index <= stacks->stack_size)
	{
		if (stacks->stack_size % groups != 0 && counter == groups - 1)
			max_index = stacks->stack_size;
		stacks->max_values[counter] = max_index - 1;
		counter++;
		max_index += stacks->stack_size / groups;
	}
	return (groups);
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
}
