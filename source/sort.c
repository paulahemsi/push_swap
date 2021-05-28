/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/27 21:43:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"




// static void	debug(t_list **stack_a, t_list **stack_b)
// {
// 	ft_putendl("stack_a");
// 	ft_lstiter(*stack_a, &ft_putnbr);
// 	ft_putendl("stack_b");
// 	ft_lstiter(*stack_b, &ft_putnbr);
// }


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

static int	is_reverse_sorted(t_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	while (stack->previous != NULL)
	{
		if (stack->content > stack->previous->content)
			return (0);
		stack = stack->previous;
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

static void	define_numbers(int *first, int *second, int *last, t_list *stack)
{
	*first = stack->content;
	*second = stack->next->content;
	while (stack->next != NULL)
		stack = stack->next;
	*last = stack->content;
}

void	order_b(t_list **stack_b)
{
	int	first;
	int	second;
	int	last;
	t_list	*stack;

	//ft_putendl("entrada order_b");
	//debug(stack_b, stack_b);
	stack = *stack_b;
	if (stack->next == NULL)
		return ;
	if (stack->next->next == NULL)
		if (stack->content < stack->next->content)
		{
			swap(stack_b);
			return ;
		}
	define_numbers(&first, &second, &last, stack);
	if (first < second)
	{
		if (first < last)
			rotate(stack_b);
		else
			swap(stack_b);
	}
	//ft_putendl("saída order_b");
	//debug(stack_b, stack_b);
}


void	lets_sort(t_list **stack_a, t_list **stack_b, int total_numbers)
{
	int	first;
	int	second;
	int	last;
	static int	controler;

	//ft_putendl("entrada");
	//debug(stack_a, stack_b);
	
	//if (is_reverse_sorted(*stack_a))
		//ft_putendl("reverse sorted");
	if (is_sorted(*stack_a))
	{
		if (is_full(*stack_a, total_numbers))
			return ;
		if (is_reverse_sorted(*stack_b))
			push(stack_b, stack_a);
		order_b(stack_b);
		//TODO organizar o b
	}
	else
	{
		define_numbers(&first, &second, &last, *stack_a);
		if ((last < first) && (last < second))
			reverse_rotate(stack_a);
		else if (second < first)
			swap(stack_a);
		push(stack_a, stack_b);
		order_b(stack_b);
		
	}
	controler++;
	//ft_printf("controler: %i\n", controler);
	//ft_putendl("saída");
	//debug(stack_a, stack_b);
	ft_printf("-------------------------------stack_a na tentativa %i de organizar------------------------------\n", controler - 1);
	ft_lstiter(*stack_a, &ft_putnbr);
	ft_putendl("stack_b final");
	ft_lstiter(*stack_b, &ft_putnbr);
	ft_printf("----------------------------------------------------------------------------------------------------------------\n");
	if (controler > 20)
		return;
	lets_sort(stack_a, stack_b, total_numbers);
}
