/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:07:54 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/09 20:10:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	resend_to_b(t_stack *stack, t_aux *aux, int limit)
{
	while ((stack->a->index <= limit)
		&& (stack->a->index >= aux->a.next_index_to_sort))
		push(&stack->a, &stack->b, &stack->instr, 'b');
}

void	return_half_to_a(t_stack *stack, t_aux *aux, int limit)
{
	int	size_b;

	size_b = ft_dlstsize(stack->b);
	if (size_b < 50)
	{
		finish_sorting(stack, aux);
		return ;
	}
	start_sorting(stack, aux);
	resend_to_b(stack, aux, limit);
	return_half_to_a(stack, aux, limit);
}
