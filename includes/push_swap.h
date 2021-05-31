/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:06:40 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/31 13:16:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"

void	return_error(void);
/*
** operations
*/
void	swap(t_dlist **stack, t_list **instr, char id);
void	rotate(t_dlist **stack, t_list **instr, char id);
void	reverse_rotate(t_dlist **stack, t_list **instr, char id);
void	push(t_dlist **origin_stack, t_dlist **dest_stack, t_list **instr, char id);
/*
** sorting
*/
void	lets_sort(t_dlist **stack_a, t_dlist **stack_b, int total_numbers, t_list **instr);
int		is_sorted(t_dlist *stack);
int		is_reverse_sorted(t_dlist *stack);
int		is_full(t_dlist *stack, int total_numbers);
/*
** aux
*/
void	quick_sort(int *array, int left, int right);

#endif
