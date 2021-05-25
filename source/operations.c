/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:05:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/25 19:22:26 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	*stack = second;
}

//void	push(t_list *origin, t_list *dest)
// {
	
// }

/*
** shift_up
*/
void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

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