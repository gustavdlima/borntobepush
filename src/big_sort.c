#include "push_swap.h"

/*
Função que divide em grupos e retorna o numero de grupos
*/
int	split_in_groups(t_stacks *stacks)
{
	int	groups;
	int	max_value;
	int	*big;

	groups = ft_sqrt(stacks->stack_size);
	big = (int *)malloc(sizeof(int) * groups);
	max_value = stacks->stack_size / groups;
	while (max_value != stacks->stack_size)
	{
		if (groups % stacks->stack_size != 0)


	}


	stack 10
	grupos 3
	3 3 4
	return (groups);
}

// quantidade de elemento em cada grupo
// maior elemento de cada grupo

/*
Função auxiliar que escaneia a stack_a verificando se ainda restam itens
do grupo atual
*/

void	parse_to_push(t_stacks *stacks, int groups)
{
	int	i;

	i = 0;
	while (i < groups)
	{
		if ()
		{
			//push a_to_b;
		}
		i++;
	}
}

// Group 0
// 1
// 2
// 3

// Group 1
// 4
// 5
// 6

// Group 3
// 7
// 8
// 9
// 10

//Dividir a stack em grupos. Como será feita essa divisão?
//Definir o índice máximo de cada grupo o limitador na hora de separar
//