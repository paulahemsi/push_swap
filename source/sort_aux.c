/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:16:13 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/09 20:07:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_mid_index(int bigger_index, int smallest_index)
{
	return (smallest_index + ((bigger_index - smallest_index) / 2));
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

int	last_num_index(t_dlist *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index);
}

void	order_a(t_stack *stack, t_aux *aux)
{
	if (stack->a->index == 0)
		rotate(&stack->a, &stack->instr, 'a');
	while (((stack->a->index + 1) == (stack->a->next->index))
		&& ((stack->a->index - 1) == last_num_index(stack->a)))
		rotate(&stack->a, &stack->instr, 'a');
	if (((stack->a->index - 1) == last_num_index(stack->a)))
		rotate(&stack->a, &stack->instr, 'a');
	aux->a.next_index_to_sort = last_num_index(stack->a) + 1;
}
