/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/05 01:13:45 by phemsi-a         ###   ########.fr       */
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
	num->last = stack->content;
}

// static int	smaller_than_middle(t_num *num, t_dlist *stack, t_aux *aux)
// {
// 	num->first = stack->content;
// 	num->second = stack->next->content;
// 	while (stack->next != NULL)
// 		stack = stack->next;
// 	num->last = stack->content;
// 	if ((num->first < aux->middle_num) || (num->second < aux->middle_num) || (num->last < aux->middle_num))
// 		return (1);
// 	return (0);
// }

// static void	order_b(t_dlist **stack_b, t_list **instr)
// {
// 	t_num	num;
// 	t_dlist	*stack;

// 	stack = *stack_b;
// 	if (stack == NULL || stack->next == NULL)
// 		return ;
// 	if (stack->next->next == NULL)
// 	{
// 		if (stack->content < stack->next->content)
// 		{
// 			swap(stack_b, instr, 'b');
// 			return ;
// 		}
// 	}
// 	define_numbers(&num, stack);
// 	if (num.first < num.second)
// 	{
// 		if (num.first < num.last)
// 			rotate(stack_b, instr, 'b');
// 		else
// 			swap(stack_b, instr, 'b');
// 		//TODO dá pra incluir o reverse_rotate aqui tb
// 	}
// }

// static void	order_a(t_dlist **stack_a, t_list **instr)
// {
// 	t_num num;
// 	t_dlist	*stack;

// 	ft_printf("order_a\n");
// 	stack = *stack_a;
// 	if (stack == NULL || stack->next == NULL)
// 		return ;
// 	if (stack->next->next == NULL)
// 	{
// 		if (stack->content > stack->next->content)
// 		{
// 			swap(stack_a, instr, 'a');
// 			return ;
// 		}
// 	}
	
// 	define_numbers(&num, stack);
// 	if (num.first > num.second)
// 	{
// 		if (num.first > num.last)
// 			rotate(stack_a, instr, 'a');
// 		else
// 			swap(stack_a, instr, 'a');
// 	}
// 	else
// 		reverse_rotate(stack_a, instr, 'a');
// }

// static int reverse_rotation_is_quicker(t_dlist *stack_a, t_aux *aux)
// {
// 	int	i;
// 	int	steps_to_rotate;
// 	int	steps_to_reverse_rotate;

// 	i = 0;
// 	steps_to_rotate = -1;
// 	while (stack_a->next != NULL)
// 	{
// 		if ((stack_a->content > aux->middle_num) && (steps_to_rotate == -1))
// 			steps_to_rotate = i;
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// 	i = 0;
// 	steps_to_reverse_rotate = -1;
// 	while (stack_a->previous != NULL)
// 	{
// 		if ((stack_a->content > aux->middle_num) && (steps_to_reverse_rotate == -1))
// 			steps_to_reverse_rotate = i;
// 		stack_a = stack_a->previous;
// 		i++;
// 	}
// 	if (steps_to_reverse_rotate < steps_to_rotate)
// 		return (1);
// 	return (0);
// }

static int reverse_rotation_is_quicker(t_dlist *stack, int number)
{
	int	i;
	int	steps_to_rotate;
	int	steps_to_reverse_rotate;

	i = 0;
	steps_to_rotate = 0;
	steps_to_reverse_rotate = 0;
	while (stack->next != NULL)
	{
		if (stack->content == number)
		{
			steps_to_rotate = i;
			break ;
		}
		stack = stack->next;
		i++;
	}
	i = 0;
	while (stack->previous != NULL)
	{
		if (stack->content == number)
		{
			steps_to_reverse_rotate = i;
			break ;
		}
		stack = stack->previous;
		i++;
	}
	if (steps_to_reverse_rotate < steps_to_rotate)
		return (1);
	return (0);
}

// static int is_time_to_go_back(t_dlist *stack_b, t_dlist *stack_a, t_aux *aux)
// {
// 	int i;

// 	i = 0;
// 	while (i < aux->total_num)
// 	{
// 		if (aux->ordered_array[i] == stack_a->content)
// 			break ;
// 		i++;
// 	}
// 	return (stack_b->content == aux->ordered_array[i - 1]);
// }

static int	any_small_in_stack_a(t_dlist *stack_a, t_aux *aux)
{
	
	while (stack_a != NULL)
	{
		if (stack_a->content < aux->middle_num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

// static void	sort_three(t_num *num, t_dlist **stack, t_aux *aux)
// {
// 	if (num->first > num->second)
// 	{
// 		if (num->first > num->last)
// 		{
// 			if (num->second > num->last)
// 			{
// 				swap(stack, &aux->instr, 'a');
// 				reverse_rotate(stack, &aux->instr, 'a');
// 			}
// 			else
// 				rotate(stack, &aux->instr, 'a');
			
// 		}
// 		else
// 			swap(stack, &aux->instr, 'a');
// 	}
// 	else
// 	{
// 		if (num->first < num->last)
// 		{
// 			swap(stack, &aux->instr, 'a');
// 			rotate(stack, &aux->instr, 'a');
// 		}
// 		else
// 			reverse_rotate(stack, &aux->instr, 'a');
// 	}
// }

static void	send_half_to_b(t_stack *stack, t_aux *aux)
{
	int		size_a;
	int		i;

	size_a = ft_dlstsize(stack->a);
	i = 0;
	while ((i < size_a) && (any_small_in_stack_a(stack->a, aux)))
	{
		if (stack->a->content < aux->middle_num)
			push(&stack->a, &stack->b, &aux->instr, 'b');
		else
			rotate(&stack->a, &aux->instr, 'a');
		i++;
	}
}

// static int	find_middle(t_stack *stack)
// {
	
// }

static void	return_half_to_a(t_stack *stack, t_aux *aux, int middle_b)
{
	int		size_b;
	t_num	num;
	int		i;

	ft_printf("entrando na return half to a:\n");
	debug(stack->a, stack->b);
	size_b = ft_dlstsize(stack->b);
	i = 0;
	while (i < size_b)
	{
		define_numbers(&num, stack->b);
		ft_printf("NUMBERS:\n	beginning %i\n	first %i\n	highest %i\n	last %i\n	second %i\n ", aux->beginning, num.first, num.highest, num.last, num.second);
		if (size_b < 15)
		{
			if (num.highest == num.first)
				push(&stack->b, &stack->a, &aux->instr, 'a');
			else
			{
				if (num.first == aux->beginning)
				{
					push(&stack->b, &stack->a, &aux->instr, 'a');
					rotate(&stack->a, &aux->instr, 'a');
					aux->beginning++;
				}
				else
				{
					if (reverse_rotation_is_quicker(stack->b, num.highest))
						reverse_rotate(&stack->b, &aux->instr, 'b');
					else
						rotate(&stack->b, &aux->instr, 'b');
				}
			}
		}
		else
		{
			if (num.first > middle_b)
				push(&stack->b, &stack->a, &aux->instr, 'a');
			else
			{
				if (num.first == 1)
				{
					push(&stack->b, &stack->a, &aux->instr, 'a');
					rotate(&stack->a, &aux->instr, 'a');
					aux->beginning++;
				}
				else
					rotate(&stack->b, &aux->instr, 'b');
			}
		}
		i++;
	}
	define_numbers(&num, stack->a);
	// while ()//TODO comparar se index do primeiro é um acima do index do ultimo, se não for, RA
	// {
		
	// }
	ft_printf("saindo na return half to a:\n");
	debug(stack->a, stack->b);
}


void	lets_sort(t_stack *stack, t_aux *aux)
{

	static	int controler;
	ft_printf("entrando na lets sort:\n");
	debug(stack->a, stack->b);
	if (is_sorted(stack->a) && is_full(stack->a, aux->total_num))
		return ;
	send_half_to_b(stack, aux);
	return_half_to_a(stack, aux, (aux->middle_num / 2));
	
//------------------------------------------------------------
	ft_printf("controler %i\nSaíndo da lets sort:\n", controler);
	debug(stack->a, stack->b);
	controler ++;
	if (controler > 0)
		return ;
	lets_sort(stack, aux);
}
