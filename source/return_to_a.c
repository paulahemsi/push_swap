/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:07:54 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/06 18:23:36 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	last_num_index(t_dlist *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index);
}

void	order_a(t_stack *stack, t_aux *aux)
{
	if (stack->a->index == 0)
		rotate(&stack->a, &stack->instr, 'a');
	while (((stack->a->index + 1) == (stack->a->next->index)) && ((stack->a->index - 1) == last_num_index(stack->a)))
		rotate(&stack->a, &stack->instr, 'a');
	if (((stack->a->index - 1) == last_num_index(stack->a)))
	rotate(&stack->a, &stack->instr, 'a');
	aux->a.next_index_to_sort = last_num_index(stack->a) + 1;
}

static void	send_next_bigger_to_a(t_stack *stack, t_aux *aux)
{
	push(&stack->b, &stack->a, &stack->instr, 'a');
	aux->b.higher_index--;
}

static void	send_next_smaller_to_a(t_stack *stack, t_aux *aux)
{
	push(&stack->b, &stack->a, &stack->instr, 'a');
	rotate(&stack->a, &stack->instr, 'a');
	aux->a.next_index_to_sort++;
	aux->b.lower_index++;
}

static void	finish_sorting(t_stack *stack, t_aux *aux)
{
	int	size_b;

	size_b = ft_dlstsize(stack->b);
	if (size_b == 0)
	{
		order_a(stack, aux);
		ft_printf("acabou finish sorting, b tá vazio\n");
		debug(stack->a, stack->b);
		return ;
	}
	else if (size_b == 1)
		push(&stack->b, &stack->a, &stack->instr, 'a');
	else if (stack->b->index == aux->a.next_index_to_sort)
		send_next_smaller_to_a(stack, aux);
	else if (stack->b->index == aux->b.higher_index)
		send_next_bigger_to_a(stack, aux);
	else if (reverse_rotation_is_quicker(stack->b, aux->a.next_index_to_sort)) //TODO higher index e comparar
		reverse_rotate(&stack->b, &stack->instr, 'b');
	else
		rotate(&stack->b, &stack->instr, 'b');
	finish_sorting(stack, aux);
}

void	return_half_to_a(t_stack *stack, t_aux *aux, int limit)
{
	int	size_b;

	size_b = ft_dlstsize(stack->b);
	if (size_b < 13)
	{
		finish_sorting(stack, aux);
		return ;
	}
	limit ++;
	if (limit > 30)
		return ;
	ft_printf("limit %i\nna saída da return to a:\n", limit);
	debug(stack->a, stack->b);
	return_half_to_a(stack, aux, limit);
}