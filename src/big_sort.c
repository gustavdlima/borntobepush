#include "push_swap.h"

/*
Função que divide em grupos e retorna o numero de grupos
*/
int	split_in_groups(t_stacks *stacks)
{
	int	groups;
	int	max_index;
	int	counter;
	int	elements_per_group;
	int	elements_last_group;

					// stack_size = 119 //stack_size = 500
	groups = ft_sqrt(stacks->stack_size);			// groups = 10 //groups = 22
	if (stacks->stack_size % groups)	// stack_size % groups == 9
		groups++;									// groups = 11 //groups 23
	stacks->max_values = (int *)malloc(sizeof(int) * groups); 
	// os 10 primeiros grupos preencho com stack_size/groups elementos, e o último grupo com o q sobrar
	elements_per_group = stacks->stack_size / groups; //119 / 11 = 10 elements // 500 / 23 = 21 elements -> Temos 23 grupos com 21 elementos cada = 483
	if (stacks->stack_size % elements_per_group)
		elements_last_group = stacks->stack_size - ((groups - 1) * elements_per_group); // 500 - ((23 - 1) * 21) = 38
	/*
	No final optamos por ter 22 groups com 21 elementos e 1 grupo com 38 ao invés de
	23 groups com 21 elementos e 1 grupo com 17 elementos 
	*/
	max_index = stacks->stack_size / groups;		// 120/10 = 12
	counter = 0;						
	while (max_index != stacks->stack_size)	//	119 groups = 10
	{
		if (stacks->stack_size % groups != 0 && counter == groups - 1)
			max_index++;
		stacks->max_values[counter] = max_index - 1;
		counter++;
		max_index += max_index;
	}
	return (groups);
}

/*
100 elementos iniciais na lista
a lista se dividirá então em sqrt(100) = 10 segmentos
cada segmento terá # total (100) / # segmentos (10) = 10 elementos
10 grupos x 10 elementos = 100 elementos == 0100 elementos iniciais

devolvendo o próximo quadrado perfeito:
105 elementos iniciais na lista
a lista se dividirá então em sqrt(105) = 11 segmentos
cada segmento terá # total (105) / # segmentos (11) = 9
11 grupos x 9 elementos = 99 elementos != 105 elementos iniciais

devolvendo o quadrado perfeito anterior:
105 elementos iniciais na lista
a lista se dividirá então em sqrt(105) = 9 segmentos
cada segmento terá # total (105) / # segmentos (9) = 11 elementos
9 grupos x 11 elementos = 99 elementos != 105 elementos iniciais









*/

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

void	big_sort(t_stacks *stacks)
{
	split_in_groups(stacks);
}