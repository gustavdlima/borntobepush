/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:57:33 by gusalves          #+#    #+#             */
/*   Updated: 2022/02/13 22:57:33 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_asc(t_doubly_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}
