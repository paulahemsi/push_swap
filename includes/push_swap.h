/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:06:40 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/05 01:00:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"

typedef struct	s_stack
{
	t_dlist		*a;
	t_dlist		*b;
}				t_stack;

typedef struct	s_aux
{
	int			*ordered_array;
	t_list		*instr;
	int			total_num;
	int			middle_num;
	int			beginning;
}				t_aux;

typedef struct	s_num
{
	int			first;
	int			highest;
	// int			beginning;
	int			second;
	int			last;
}				t_num;
/*
** system
*/
void	return_error(void);
void	clear(t_stack *stack, t_aux *aux);
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
void	lets_sort(t_stack *stack, t_aux *aux);
int		is_sorted(t_dlist *stack);
int		is_reverse_sorted(t_dlist *stack);
int		is_full(t_dlist *stack, int total_numbers);
/*
** aux
*/
void	quick_sort(int *array, int left, int right);

#endif
