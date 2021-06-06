/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/06 17:40:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	debug(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_putendl("stack_a");
	ft_dlstiter(stack_a, &ft_putnbr);
	ft_putendl("stack_b");
	ft_dlstiter(stack_b, &ft_putnbr);
}

// static void	define_numbers(t_num *num, t_dlist *stack)
// {
// 	num->first = stack->content;
// 	if (stack->next)
// 		num->second = stack->next->content;
// 	num->highest = INT_MIN;
// 	if (stack->next == NULL)
// 		num->highest = stack->content;
// 	while (stack->next != NULL)
// 	{
// 		if (stack->content > num->highest)
// 			num->highest = stack->content;
// 		stack = stack->next;
// 	}
// 	if (stack->content > num->highest)
// 			num->highest = stack->content;
// 	num->last = stack->content;
// }





// static void	send_next_smaller_to_a(t_stack *stack, t_aux *aux)
// {
// 	push(&stack->b, &stack->a, &stack->instr, 'a');
// 	rotate(&stack->a, &stack->instr, 'a');
// 	aux->last_ordered_index++;
// 	aux->next_small_num = aux->ordered_array[aux->last_ordered_index + 1];
// }

// static void	return_half_to_a(t_stack *stack, t_aux *aux, int limit)
// {
// 	int		size_b;
// 	int		i;
// 	t_num	num;

// 	ft_printf("-------------->entrando na return half to a:\n");
// 	debug(stack->a, stack->b);
// 	if (is_full(stack->a, aux->total_num) && (aux->ordered_array[aux->last_ordered_index] == limit))
// 		return ;
// 	if (any_small_in_stack_a(stack->a, aux))
// 		send_half_to_b(stack, aux);
// 	else
// 		order_a(stack, aux);
// 	i = 0;
// 	size_b = ft_dlstsize(stack->b);
// 	while (i < size_b)
// 	{
// 		define_numbers(&num, stack->b);
// 		aux->middle_num = define_mid_index( (aux->top_index_in_b), (aux->bottom_index_in_b));
// 		if (stack->b->content == aux->next_small_num)
// 			send_next_smaller_to_a(stack, aux);
// 		else if (stack->b->content > aux->middle_num)
// 			push(&stack->b, &stack->a, &stack->instr, 'a');
// 		else if (reverse_rotation_is_quicker(stack->b, num.highest))
// 			reverse_rotate(&stack->b, &stack->instr, 'b');
// 		else
// 			rotate(&stack->b, &stack->instr, 'b');
// 		i++;
// 	}
	

// 	ft_printf("saindo na return half to a:---------------->\n");
// 	debug(stack->a, stack->b);
// 	return_half_to_a(stack, aux, limit);
// }


void	lets_sort(t_stack *stack, t_aux *aux)
{
	
//************************************************************************

	ft_printf("entrando na lets sort:\n");
	debug(stack->a, stack->b);
	
//************************************************************************
	
	if (is_sorted(stack->a) && is_full(stack->a, aux->total_num))
		return ;
	send_half_to_b(stack, aux);
	return_half_to_a(stack, aux, aux->b.higher_index);

//************************************************************************
	
	static	int controler;
	ft_printf("controler %i\nSaíndo da lets sort:\n", controler);
	debug(stack->a, stack->b);
	controler ++;
	if (controler > 10)
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
// 			push(&stack->b, &stack->a, &stack->instr, 'a');
// 		else
// 		{
// 			if (num.first == aux->next_small_num)
// 				send_next_smaller_to_a(stack, aux);
// 			else
// 			{
// 				if (reverse_rotation_is_quicker(stack->b, num.highest))
// 					reverse_rotate(&stack->b, &stack->instr, 'b');
// 				else
// 					rotate(&stack->b, &stack->instr, 'b');
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if (num.first > define_mid_index( aux->top_index_in_b, aux->bottom_index_in_b))//!isso pode dar xabu pq conforme passa pro a, mudam os top e bottom indexes
// 			push(&stack->b, &stack->a, &stack->instr, 'a');
// 		else
// 		{
// 			if (num.first == aux->next_small_num)
// 				send_next_smaller_to_a(stack, aux);
// 			else
// 				rotate(&stack->b, &stack->instr, 'b');
// 		}
// 	}