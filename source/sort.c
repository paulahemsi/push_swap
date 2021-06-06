/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/06 11:22:48 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	debug(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_putendl("stack_a");
	ft_dlstiter(stack_a, &ft_putnbr);
	ft_putendl("stack_b");
	ft_dlstiter(stack_b, &ft_putnbr);
}

static void	define_numbers(t_num *num, t_dlist *stack)
{
	num->first = stack->content;
	if (stack->next)
		num->second = stack->next->content;
	num->highest = INT_MIN;
	if (stack->next == NULL)
		num->highest = stack->content;
	while (stack->next != NULL)
	{
		if (stack->content > num->highest)
			num->highest = stack->content;
		stack = stack->next;
	}
	if (stack->content > num->highest)
			num->highest = stack->content;
	num->last = stack->content;
}

static void	send_half_to_b(t_stack *stack, t_aux *aux)
{
	int		size_a;
	int		i;

	aux->top_index_in_b = INT_MIN;
	aux->bottom_index_in_b = INT_MAX;
	size_a = ft_dlstsize(stack->a);
	i = 0;
	aux->middle_num = define_middle_number(aux, (aux->total_num - 1), (aux->last_ordered_index + 1));
	ft_printf("middle num %i\n", aux->middle_num);
	while ((i < size_a) && (any_small_in_stack_a(stack->a, aux)))
	{
		if (stack->a->content <= aux->middle_num)
		{
			push(&stack->a, &stack->b, &aux->instr, 'b');
			if (stack->b->index > aux->top_index_in_b)
				aux->top_index_in_b = stack->a->index;
			else if (stack->b->index < aux->bottom_index_in_b)
				aux->bottom_index_in_b = stack->a->index;
		}
		else
			rotate(&stack->a, &aux->instr, 'a');
		i++;
	}
}

static void	order_a(t_stack *stack, t_aux *aux)
{
	while ((stack->a->index + 1) == (stack->a->next->index))
		rotate(&stack->a, &aux->instr, 'a');
	aux->last_ordered_index = stack->a->index;
	rotate(&stack->a, &aux->instr, 'a');
	aux->next_small_num = aux->ordered_array[aux->last_ordered_index + 1];
}

static void	send_next_smaller_to_a(t_stack *stack, t_aux *aux)
{
	push(&stack->b, &stack->a, &aux->instr, 'a');
	rotate(&stack->a, &aux->instr, 'a');
	aux->last_ordered_index++;
	aux->next_small_num = aux->ordered_array[aux->last_ordered_index + 1];
}

static void	return_half_to_a(t_stack *stack, t_aux *aux, int limit)
{
	int		size_b;
	int		i;
	t_num	num;

	ft_printf("-------------->entrando na return half to a:\n");
	debug(stack->a, stack->b);
	if (is_full(stack->a, aux->total_num) && (aux->ordered_array[aux->last_ordered_index] == limit))
		return ;
	if (any_small_in_stack_a(stack->a, aux))
		send_half_to_b(stack, aux);
	else
		order_a(stack, aux);
	i = 0;
	size_b = ft_dlstsize(stack->b);
	while (i < size_b)
	{
		define_numbers(&num, stack->b);
		aux->middle_num = define_middle_number(aux, (aux->top_index_in_b), (aux->bottom_index_in_b));
		if (stack->b->content == aux->next_small_num)
			send_next_smaller_to_a(stack, aux);
		else if (stack->b->content > aux->middle_num)
			push(&stack->b, &stack->a, &aux->instr, 'a');
		else if (reverse_rotation_is_quicker(stack->b, num.highest))
			reverse_rotate(&stack->b, &aux->instr, 'b');
		else
			rotate(&stack->b, &aux->instr, 'b');
		i++;
	}
	
	/*
	se o last_ordered_index for o index mais alto que foi mandado para o b
		retornar
	se tiver algum pra baixo do limit no a
		mandar pro b
	passar por todo b analisando número no topo //? valeria a pena tb analisar o último e segundo para dar swap/rrb ou é melhor manter apenas rb?
		se número do topo for next_small_num,
			send_next_smaller_to_a
		se não, se for da maior metade que está em b
			push_a
		se não
			rb
	*/
	ft_printf("saindo na return half to a:---------------->\n");
	debug(stack->a, stack->b);
	return_half_to_a(stack, aux, limit);
}


void	lets_sort(t_stack *stack, t_aux *aux)
{
	
//************************************************************************

	ft_printf("entrando na lets sort:\n");
	debug(stack->a, stack->b);
	
//************************************************************************
	
	if (is_sorted(stack->a) && is_full(stack->a, aux->total_num))
		return ;
	send_half_to_b(stack, aux);
	return_half_to_a(stack, aux, aux->top_index_in_b);

//************************************************************************
	
	static	int controler;
	ft_printf("controler %i\nSaíndo da lets sort:\n", controler);
	debug(stack->a, stack->b);
	controler ++;
	if (controler > 1)
		return ;
		
//************************************************************************

	lets_sort(stack, aux);
}















// return_half_to_a antiga

// //!alguma hora precisa de rra pra não deixar números maiores no meio do a organizado
// 	ft_printf("entrando na return half to a:\n");
// 	debug(stack->a, stack->b);
// 	if (is_full(stack->a, aux->total_num))
// 	{
// 		order_a(stack, aux);
// 		return ;
// 	}
// 	size_b = ft_dlstsize(stack->b);
// 	if (aux->last_ordered_index > -1)
// 		aux->next_small_num = aux->ordered_array[aux->last_ordered_index + 1];
// 	define_numbers(&num, stack->b);
// 	if (size_b < 15)
// 	{
// 		if (num.highest == num.first)
// 			push(&stack->b, &stack->a, &aux->instr, 'a');
// 		else
// 		{
// 			if (num.first == aux->next_small_num)
// 				send_next_smaller_to_a(stack, aux);
// 			else
// 			{
// 				if (reverse_rotation_is_quicker(stack->b, num.highest))
// 					reverse_rotate(&stack->b, &aux->instr, 'b');
// 				else
// 					rotate(&stack->b, &aux->instr, 'b');
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if (num.first > define_middle_number(aux, aux->top_index_in_b, aux->bottom_index_in_b))//!isso pode dar xabu pq conforme passa pro a, mudam os top e bottom indexes
// 			push(&stack->b, &stack->a, &aux->instr, 'a');
// 		else
// 		{
// 			if (num.first == aux->next_small_num)
// 				send_next_smaller_to_a(stack, aux);
// 			else
// 				rotate(&stack->b, &aux->instr, 'b');
// 		}
// 	}