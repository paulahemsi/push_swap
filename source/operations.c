/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:05:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 10:05:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

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
}

void	push(t_list **origin_stack, t_list **dest_stack)
{
	t_list	*origin;
	t_list	*dest;

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
		return ;
	}
	dest->previous = origin;
	origin->next = dest;
	*dest_stack = dest->previous;
}

/*
** shift_up
*/
void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL)
		return ;
	first = *stack;
	last = *stack;
	first->next->previous = NULL;
	*stack = first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

/*
** shift_down
*/
void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

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
}