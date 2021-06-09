/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:51:34 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/08 22:14:21 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calculate_rotation_steps(t_dlist *stack, int target_number, int steps)
{
	if (!stack)
		return INT_MAX;
	if (stack->index == target_number)
		return (steps) ;
	if (!stack->next)
		return INT_MAX;
	stack = stack->next;
	return (calculate_rotation_steps(stack, target_number, (steps + 1))) ;
}

static int	calculate_reverse_rotation_steps(t_dlist *stack, int target_number, int steps)
{
	if (!stack)
		return INT_MAX;
	if (stack->index == target_number)
		return (steps) ;
	if (!stack->previous)
		return INT_MAX;
	stack = stack->previous;
	return (calculate_reverse_rotation_steps(stack, target_number, (steps + 1))) ;
}

int reverse_rotation_is_quicker(t_dlist *stack, int target_number)
{
	int	rotation_steps;
	int	reverse_rotation_steps;

	rotation_steps = calculate_rotation_steps(stack, target_number, 0);
	while (stack->next != NULL)
		stack = stack->next;
	reverse_rotation_steps = calculate_reverse_rotation_steps(stack, target_number, 0);
	if (reverse_rotation_steps < rotation_steps)
		return (1);
	return (0);
}

static int	calculate_rotation_steps_multi(t_dlist *stack, int target_number, int steps)
{
	if (stack->index > target_number)
		return (steps) ;
	stack = stack->next;
	return (calculate_rotation_steps_multi(stack, target_number, (steps + 1))) ;
}

static int	calculate_reverse_rotation_steps_multi(t_dlist *stack, int target_number, int steps)
{
	if (stack->index > target_number)
		return (steps) ;
	stack = stack->previous;
	return (calculate_reverse_rotation_steps_multi(stack, target_number, (steps + 1))) ;
}

int reverse_rotation_is_quicker_multi_nums(t_dlist *stack, int first_num, t_aux *aux)
{
	int	rotation_steps_first;
	int	reverse_rotation_steps_first;
	int	rotation_steps_second;
	int	reverse_rotation_steps_second;
	t_dlist	*stack_to_check;
	

	stack_to_check = stack;
	rotation_steps_first = calculate_rotation_steps(stack_to_check, first_num, 0);
	fast_forward(&stack_to_check);
	reverse_rotation_steps_first = calculate_reverse_rotation_steps(stack_to_check, first_num, 0);
	stack_to_check = stack;
	
	rotation_steps_second = calculate_rotation_steps_multi(stack_to_check, aux->b.mid_index, 0);
	fast_forward(&stack_to_check);
	reverse_rotation_steps_second = calculate_reverse_rotation_steps_multi(stack_to_check, aux->b.mid_index, 0);
	if (reverse_rotation_steps_first < rotation_steps_first)
		if (reverse_rotation_steps_first < rotation_steps_second)
			return (1);
	if (reverse_rotation_steps_second < rotation_steps_first)
		return (1);
	return (0);
}