/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:04:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/09 17:24:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static int	is_reverse_sorted(t_dlist *stack)
// {
// 	if (stack)
// 	{
// 		while (stack->next != NULL)
// 			stack = stack->next;
// 		while (stack->previous != NULL)
// 		{
// 			if (stack->content > stack->previous->content)
// 				return (0);
// 			stack = stack->previous;
// 		}
// 	}
// 	return (1);
// }

static void	define_numbers(int *first, int *second, int *last, t_dlist *stack)
{
	*first = stack->content;
	*second = stack->next->content;
	while (stack->next != NULL)
		stack = stack->next;
	*last = stack->content;
}

// static void	order_b(t_stack *stack)
// {
// 	int	first;
// 	int	second;
// 	int	last;

// 	if (stack->b == NULL || stack->b->next == NULL)
// 		return ;
// 	if (stack->b->next->next == NULL)
// 	{
// 		if (stack->b->content < stack->b->next->content)
// 		{
// 			swap(&stack->b, &stack->instr, 'b');
// 			return ;
// 		}
// 	}
// 	define_numbers(&first, &second, &last, stack->b);
// 	if (first < second)
// 	{
// 		if (first < last)
// 			rotate(&stack->b, &stack->instr, 'b');
// 		else
// 			swap(&stack->b, &stack->instr, 'b');
// 	}
// }

static void	sort_three(t_stack *stack, int *first, int *second, int *last)
{
	if (*first > *second)
	{
		if (*last > *second)
		{
			if (*last > *first)
				swap(&stack->a, &stack->instr, 'a');
			else
				rotate(&stack->a, &stack->instr, 'a');
		}
		else
		{
			swap(&stack->a, &stack->instr, 'a');
			reverse_rotate(&stack->a, &stack->instr, 'a');
		}
	}
	else
	{
		if (*second > *last)
		{
			swap(&stack->a, &stack->instr, 'a');
			rotate(&stack->a, &stack->instr, 'a');
		}
		else
			reverse_rotate(&stack->a, &stack->instr, 'a');
	}
}

void	small_sort(t_stack *stack, t_aux *aux, int total_numbers)
{
	int	first;
	int	second;
	int	last;

	(void)aux;
	(void)total_numbers;
	// if (is_sorted(stack->a))
	// {
	// 	if (is_full(stack->a, total_numbers))
	// 		return ;
	// 	// if (is_reverse_sorted(stack->b))
	// 	// 	push(&stack->b, &stack->a, &stack->instr, 'a');
	// 	// order_b(stack);
	// }
	// else
	// {
		define_numbers(&first, &second, &last, stack->a);
	// 	if (ft_dlstsize(stack->a) == 3)
			sort_three(stack, &first, &second, &last);
	// 	else
	// 	{
	// 		if ((last < first) && (last < second))
	// 			reverse_rotate(&stack->a, &stack->instr, 'a');
	// 		else if (second < first)
	// 			swap(&stack->a, &stack->instr, 'a');
	// 		//push(&stack->a, &stack->b, &stack->instr, 'b');
	// 		//order_b(stack);
	// 	}
	// }
	// small_sort(stack, aux, total_numbers);
}
