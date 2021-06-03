/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/03 19:37:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	debug(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_putendl("stack_a");
	ft_dlstiter(*stack_a, &ft_putnbr);
	ft_putendl("stack_b");
	ft_dlstiter(*stack_b, &ft_putnbr);
}

static void	define_numbers(int *first, int *second, int *last, t_dlist *stack)
{
	*first = stack->content;
	*second = stack->next->content;
	while (stack->next != NULL)
		stack = stack->next;
	*last = stack->content;
}

static int	smaller_than_middle(t_num *num, t_dlist *stack, t_aux *aux)
{
	num->first = stack->content;
	num->second = stack->next->content;
	while (stack->next != NULL)
		stack = stack->next;
	num->last = stack->content;
	if ((num->first < aux->middle_num) || (num->second < aux->middle_num) || (num->last < aux->middle_num))
		return (1);
	return (0);
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

static void	order_a(t_dlist **stack_a, t_list **instr)
{
	int	first;
	int	second;
	int	last;
	t_dlist	*stack;

	ft_printf("order_a\n");
	stack = *stack_a;
	if (stack == NULL || stack->next == NULL)
		return ;
	if (stack->next->next == NULL)
	{
		if (stack->content > stack->next->content)
		{
			swap(stack_a, instr, 'a');
			return ;
		}
	}
	define_numbers(&first, &second, &last, stack);
	if (first > second)
	{
		if (first > last)
			rotate(stack_a, instr, 'a');
		else
			swap(stack_a, instr, 'a');
	}
	if (!(is_sorted(stack)))
		reverse_rotate(stack_a, instr, 'a');
}

static int reverse_rotation_is_quicker(t_dlist *stack_a, t_aux *aux)
{
	int	i;
	int	steps_to_rotate;
	int	steps_to_reverse_rotate;

	i = 0;
	steps_to_rotate = -1;
	while (stack_a->next != NULL)
	{
		if ((stack_a->content > aux->middle_num) && (steps_to_rotate == -1))
			steps_to_rotate = i;
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	steps_to_reverse_rotate = -1;
	while (stack_a->previous != NULL)
	{
		if ((stack_a->content > aux->middle_num) && (steps_to_reverse_rotate == -1))
			steps_to_reverse_rotate = i;
		stack_a = stack_a->previous;
		i++;
	}
	if (steps_to_reverse_rotate < steps_to_rotate)
		return (1);
	return (0);
}

static int is_time_to_go_back(t_dlist *stack_b, t_dlist *stack_a, t_aux *aux)
{
	int i;

	i = 0;
	while (i < aux->total_num)
	{
		if (aux->ordered_array[i] == stack_a->content)
			break ;
		i++;
	}
	return (stack_b->content == aux->ordered_array[i - 1]);
}

static int	any_small_in_stack_a(t_dlist *stack_a, t_aux *aux)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content < aux->middle_num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	lets_sort(t_dlist **stack_a, t_dlist **stack_b, t_aux *aux)
{
	t_num	num;
	int		rr_is_quicker;
	static	int controler;

	if (is_sorted(*stack_a))
	{
		if (is_full(*stack_a, aux->total_num))
			return ;
		if (is_time_to_go_back(*stack_b, *stack_a, aux))
		{
			ft_printf("time to go back\n");
			push(stack_b, stack_a, &aux->instr, 'a');
		}
		else
		{
			ft_printf("ordenando o b\n");
			order_b(stack_b, &aux->instr);
		}
	}
	else
	{
		if (any_small_in_stack_a(*stack_a, aux))
		{
			if (smaller_than_middle(&num, *stack_a, aux))
			{
				if ((num.last < num.first) && (num.last < num.second))
					reverse_rotate(stack_a, &aux->instr, 'a');
				else if (num.second < num.first)
					swap(stack_a, &aux->instr, 'a');
				push(stack_a, stack_b, &aux->instr, 'b');
				order_a(stack_a, &aux->instr);
				order_b(stack_b, &aux->instr);
			}
			else
			{
				rr_is_quicker = reverse_rotation_is_quicker(*stack_a, aux);
				ft_printf("rr_is_quicker? %i\n", rr_is_quicker);
				if (rr_is_quicker)
					reverse_rotate(stack_a, &aux->instr, 'a');
				else
					rotate(stack_a, &aux->instr, 'a');
			}
		}
		else
		{
			order_a(stack_a, &aux->instr);
			if (!(is_reverse_sorted(*stack_b)))
				order_b(stack_b, &aux->instr);
		}
	}
	ft_printf("controler %i\n", controler);
	debug(stack_a, stack_b);
	controler ++;
	if (controler > 30)
		return ;
	lets_sort(stack_a, stack_b, aux);
}
