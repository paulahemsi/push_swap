/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:16:13 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/08 12:54:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	define_mid_index(int bigger_index, int smallest_index)
{
	return (smallest_index + ((bigger_index - smallest_index) / 2)) ;
}

void	rewind(t_dlist **stack_to_rewind)
{
	t_dlist	*stack;

	stack = *stack_to_rewind;
	while (stack->previous != NULL)
		stack = stack->previous;
	*stack_to_rewind = stack;
}

void	fast_forward(t_dlist **stack_to_fast_forward)
{
	t_dlist	*stack;

	stack = *stack_to_fast_forward;
	while (stack->next != NULL)
		stack = stack->next;
	*stack_to_fast_forward = stack;
}
