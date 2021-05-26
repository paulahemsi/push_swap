/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/26 11:32:00 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	is_full(t_list *stack, int total_numbers)
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

void	lets_sort(t_list **stack_a, t_list **stack_b, int total_numbers)
{
	stack_b++;
	if (is_sorted(*stack_a) && is_full(*stack_a, total_numbers))
		return ;
	ft_putendl("not sorted");
}
