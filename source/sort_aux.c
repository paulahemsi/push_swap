/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:16:13 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/06 16:03:25 by phemsi-a         ###   ########.fr       */
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