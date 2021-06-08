/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:15:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/07 23:07:41 by phemsi-a         ###   ########.fr       */
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

void	lets_sort(t_stack *stack, t_aux *aux)
{
	if (is_sorted(stack->a) && is_full(stack->a, aux->total_num))
		return ;
	send_half_to_b(stack, aux);
	return_half_to_a(stack, aux, aux->b.higher_index);
	lets_sort(stack, aux);
}
