/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:04:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/14 14:37:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	define_numbers(int *first, int *second, int *last, t_dlist *stack)
{
	*first = stack->content;
	*second = stack->next->content;
	while (stack->next != NULL)
		stack = stack->next;
	*last = stack->content;
}

static void	sort_three(t_stack *stack, int *first, int *second, int *last)
{
	if (is_sorted(stack->a))
		return ;
	if ((*first > *second && *last > *second && *first < *last)
		|| (*first > *second && *last < *second && *first > *last)
		|| (*first < *second && *last < *second && *first < *last))
		swap(&stack->a, &stack->instr, 'a');
	define_numbers(first, second, last, stack->a);
	if (*first > *second && *last > *second && *first > *last)
		rotate(&stack->a, &stack->instr, 'a');
	if (*first < *second && *last < *second && *first > *last)
		reverse_rotate(&stack->a, &stack->instr, 'a');
}

static void	return_to_a(t_stack *stack)
{
	if (!stack->b)
		return ;
	if (stack->b->index == (last_num_index(stack->a) + 1))
	{
		push(&stack->b, &stack->a, &stack->instr, 'a');
		rotate(&stack->a, &stack->instr, 'a');
	}
	else
		swap(&stack->b, &stack->instr, 'b');
	return_to_a(stack);
}

static void	send_to_b(t_stack *stack, t_aux *aux, int total_numbers)
{
	if (ft_dlstsize(stack->a) == 3)
		return ;
	if (stack->a->index >= 3)
	{
		aux->a.higher_index--;
		push(&stack->a, &stack->b, &stack->instr, 'b');
	}
	else if (reverse_rotation_is_quicker(stack->a, (aux->a.higher_index)))
		reverse_rotate(&stack->a, &stack->instr, 'a');
	else
		rotate(&stack->a, &stack->instr, 'a');
	send_to_b(stack, aux, total_numbers);
}

void	small_sort(t_stack *stack, t_aux *aux, int total_numbers)
{
	int	first;
	int	second;
	int	last;

	(void)aux;
	if (is_sorted(stack->a) && is_full(stack->a, total_numbers))
		return ;
	if (ft_dlstsize(stack->a) == 2)
	{
		swap(&stack->a, &stack->instr, 'a');
		return ;
	}
	if (ft_dlstsize(stack->a) == 3)
	{
		define_numbers(&first, &second, &last, stack->a);
		sort_three(stack, &first, &second, &last);
		return_to_a(stack);
	}
	else
		send_to_b(stack, aux, total_numbers);
	small_sort(stack, aux, total_numbers);
}
