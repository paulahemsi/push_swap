/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:16:13 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/05 15:30:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_dlist *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
		{
			if (stack->content > stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

int	is_reverse_sorted(t_dlist *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
			stack = stack->next;
		while (stack->previous != NULL)
		{
			if (stack->content > stack->previous->content)
				return (0);
			stack = stack->previous;
		}
	}
	return (1);
}

int	is_full(t_dlist *stack, int total_numbers)
{
	int	numbers_in_stack;

	numbers_in_stack = 0;
	while (stack->next != NULL)
	{
		numbers_in_stack++;
		stack = stack->next;
	}
	numbers_in_stack++;
	if (numbers_in_stack == total_numbers)
		return (1);
	return (0);
}

int	any_small_in_stack_a(t_dlist *stack_a, t_aux *aux)
{
	while (stack_a != NULL)
	{
		if ((stack_a->content < aux->middle_num) && (stack_a->index > aux->last_ordered_index))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	define_middle_number(t_aux *aux, int bigger_index, int smallest_index)
{
	int	index;

	index = smallest_index + ((bigger_index - smallest_index) / 2);
	ft_printf("middle num %i\n", aux->middle_num);
	return (aux->ordered_array[index]) ;
}