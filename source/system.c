/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:18:29 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/14 09:10:15 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	clear(t_stack *stack, t_aux *aux)
{
	ft_dlstclear(&stack->a);
	ft_dlstclear(&stack->b);
	ft_lstclear(&stack->instr, &free);
	free(aux->ordered_array);
}
