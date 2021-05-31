/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/31 15:05:26 by phemsi-a         ###   ########.fr       */
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
		//TODO dá pra incluir o reverse_rotate aqui tb
	}
}


void	lets_sort(t_dlist **stack_a, t_dlist **stack_b, t_aux *aux)
{
	int	first;
	int	second;
	int	last;

	if (is_sorted(*stack_a))
	{
		if (is_full(*stack_a, aux->total_num))
			return ;
		if (is_reverse_sorted(*stack_b)) //TODO não precisa estar totalmente reverse sorted pra dar push pro a
			push(stack_b, stack_a, &aux->instr, 'a');
		order_b(stack_b, &aux->instr);
	}
	else
	{
		define_numbers(&first, &second, &last, *stack_a);
		if ((last < first) && (last < second))
			reverse_rotate(stack_a, &aux->instr, 'a');
		else if (second < first)
			swap(stack_a, &aux->instr, 'a');
		push(stack_a, stack_b, &aux->instr, 'b');
		order_b(stack_b, &aux->instr);
	}
	lets_sort(stack_a, stack_b, aux);
}
