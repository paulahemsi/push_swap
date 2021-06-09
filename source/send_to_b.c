/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:59:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/08 13:35:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	any_small_in_stack_a(t_dlist *stack_a, t_aux *aux)
{
	while (stack_a != NULL)
	{
		if ((stack_a->index < aux->a.mid_index) && (stack_a->index >= aux->a.next_index_to_sort))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static void	init_values(t_stack *stack, t_aux *aux, int *size_a)
{
	*size_a = ft_dlstsize(stack->a);
	aux->b.higher_index = INT_MIN;
	aux->b.lower_index = INT_MAX;
	aux->a.mid_index = define_mid_index(aux->a.higher_index, aux->a.next_index_to_sort);
}

static void	send_to_b(t_stack *stack, t_aux *aux)
{
	push(&stack->a, &stack->b, &stack->instr, 'b');
	if (stack->b->index > aux->b.higher_index)
		aux->b.higher_index = stack->b->index;
	if (stack->b->index < aux->b.lower_index)
		aux->b.lower_index = stack->b->index;
}

static void	send_smallers_to_b(t_stack *stack, t_aux *aux, int size_a)
{
	int		rotations;
	int		i;
	
	i = 0;
	rotations = 0;
	while ((i < size_a) && (any_small_in_stack_a(stack->a, aux)))
	{
		if (stack->a->index <= aux->a.mid_index)
			send_to_b(stack, aux);
		else
		{
			rotate(&stack->a, &stack->instr, 'a');
			rotations++;
		}
		i++;
	}
	if (aux->a.next_index_to_sort)
	{
		i = 0;
		while (i < rotations)
		{
			reverse_rotate(&stack->a, &stack->instr, 'a');
			i++;
		}
	}
}

void	send_half_to_b(t_stack *stack, t_aux *aux)
{
	int		size_a;

	init_values(stack, aux, &size_a);
	if ((aux->a.higher_index - aux->a.next_index_to_sort) < LAST_CHUNCK)
		while (stack->a->index > 0)
			send_to_b(stack, aux);
	else
		send_smallers_to_b(stack, aux, size_a);
}
