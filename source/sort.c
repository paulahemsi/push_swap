/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 11:56:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	debug(t_dlist **stack_a, t_dlist **stack_b)
// {
// 	ft_putendl("stack_a");
// 	ft_dlstiter(*stack_a, &ft_putnbr);
// 	ft_putendl("stack_b");
// 	ft_dlstiter(*stack_b, &ft_putnbr);
// }

static int	is_sorted(t_dlist *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	is_reverse_sorted(t_dlist *stack)
{
	
	while (stack->next != NULL)
		return (1);
	while (stack->previous != NULL)
	{
		if (stack->content > stack->previous->content)
			return (0);
		stack = stack->previous;
	}
	return (1);
}

static int	is_full(t_dlist *stack, int total_numbers)
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

static void	define_numbers(int *first, int *second, int *last, t_dlist *stack)
{
	*first = stack->content;
	*second = stack->next->content;
	while (stack->next != NULL)
		stack = stack->next;
	*last = stack->content;
}

static void	order_b(t_dlist **stack_b, t_list **instr)
{
	int	first;
	int	second;
	int	last;
	t_dlist	*stack;

	stack = *stack_b;
	if (stack == NULL || stack->next == NULL)
		return ;
	if (stack->next->next == NULL)
	{
		
		if (stack->content < stack->next->content)
		{
			swap(stack_b, instr, 'b');
			return ;
		}
	}
	define_numbers(&first, &second, &last, stack);
	if (first < second)
	{
		if (first < last)
			rotate(stack_b, instr, 'b');
		else
			swap(stack_b, instr, 'b');
	}
}


void	lets_sort(t_dlist **stack_a, t_dlist **stack_b, int total_numbers, t_list **instr)
{
	int	first;
	int	second;
	int	last;

	if (is_sorted(*stack_a))
	{
		if (is_full(*stack_a, total_numbers))
			return ;
		if (is_reverse_sorted(*stack_b))
			push(stack_b, stack_a, instr, 'a');
		order_b(stack_b, instr);
	}
	else
	{
		define_numbers(&first, &second, &last, *stack_a);
		if ((last < first) && (last < second))
			reverse_rotate(stack_a, instr, 'a');
		else if (second < first)
			swap(stack_a, instr, 'a');
		push(stack_a, stack_b, instr, 'b');
		order_b(stack_b, instr);
	}
	lets_sort(stack_a, stack_b, total_numbers, instr);
}
