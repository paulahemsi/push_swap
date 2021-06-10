/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:05:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/08 00:08:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_instruction(t_list **instr, char *content)
{
	ft_lstadd_back(instr, ft_lstnew(content));
}

void	swap(t_dlist **stack, t_list **instr, char id)
{
	t_dlist	*first;
	t_dlist	*second;

	if (*stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	if (second == NULL)
		return ;
	first->next = second->next;
	first->previous = second;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	second->previous = NULL;
	*stack = second;
	if (id == 'a')
		add_instruction(instr, "sa\n");
	else
		add_instruction(instr, "sb\n");
}

void	push(t_dlist **origin_stack, t_dlist **dest_stack,
		t_list **instr, char id)
{
	t_dlist	*origin;
	t_dlist	*dest;

	if (*origin_stack == NULL)
		return ;
	origin = *origin_stack;
	dest = *dest_stack;
	if (origin->next == NULL)
		*origin_stack = NULL;
	else
	{
		*origin_stack = origin->next;
		origin->next->previous = NULL;
	}
	if (dest == NULL)
	{
		dest = origin;
		dest->next = NULL;
		dest->previous = NULL;
		*dest_stack = dest;
		if (id == 'a')
			add_instruction(instr, "pa\n");
		else
			add_instruction(instr, "pb\n");
		return ;
	}
	dest->previous = origin;
	origin->next = dest;
	*dest_stack = dest->previous;
	if (id == 'a')
		add_instruction(instr, "pa\n");
	else
		add_instruction(instr, "pb\n");
}

/*
** shift_up
*/
void	rotate(t_dlist **stack, t_list **instr, char id)
{
	t_dlist	*first;
	t_dlist	*last;

	if (*stack == NULL)
		return ;
	first = *stack;
	last = *stack;
	if (last->next == NULL)
		return ;
	first->next->previous = NULL;
	*stack = first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	if (id == 'a')
		add_instruction(instr, "ra\n");
	else
		add_instruction(instr, "rb\n");
}

/*
** shift_down
*/
void	reverse_rotate(t_dlist **stack, t_list **instr, char id)
{
	t_dlist	*first;
	t_dlist	*last;

	if (*stack == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	first->previous = last;
	last->next = first;
	last->previous->next = NULL;
	last->previous = NULL;
	*stack = last;
	if (id == 'a')
		add_instruction(instr, "rra\n");
	else
		add_instruction(instr, "rrb\n");
}
