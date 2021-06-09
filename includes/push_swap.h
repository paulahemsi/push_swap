/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:06:40 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/09 10:57:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"

# define LAST_CHUNCK	10

typedef struct	s_stack
{
	t_dlist		*a;
	t_dlist		*b;
	t_list		*instr;
}				t_stack;

typedef struct	s_stack_aux_a
{
	int			mid_index;
	int			higher_index;
	int			next_index_to_sort;
}				t_stack_aux_a;

typedef struct	s_stack_aux_b
{
	int			mid_index;
	int			higher_index;
	int			lower_index;
}				t_stack_aux_b;

typedef struct	s_aux
{
	int				*ordered_array;
	int				total_num;
	t_stack_aux_a	a;
	t_stack_aux_b	b;
}				t_aux;

/*
** system
*/
void	return_error(void);
void	clear(t_stack *stack, t_aux *aux);
void	init(t_stack *stack, t_aux *aux, int argc, char **argv);
void	init_stack_a(int argc, char **argv, t_dlist	**stack_a);
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
int		any_small_in_stack_a(t_dlist *stack_a, t_aux *aux);
void	send_half_to_b(t_stack *stack, t_aux *aux, int controler);
void	return_half_to_a(t_stack *stack, t_aux *aux, int limit);
void	order_a(t_stack *stack, t_aux *aux);
/*
** aux
*/
void	quick_sort(int *array, int left, int right);
int		define_mid_index(int bigger_index, int smallest_index);
int		define_three_quarters_index(int bigger_index, int smallest_index);
int		reverse_rotation_is_quicker(t_dlist *stack, int target_number);
// int		reverse_rotation_is_quicker_two_nums(t_dlist *stack, int first_num, int second_num);
int		reverse_rotation_is_quicker_multi_nums(t_dlist *stack, int first_num, t_aux *aux);
void	rewind(t_dlist **stack_to_rewind);
void	fast_forward(t_dlist **stack_to_fast_forward);
void	reduce_instructions(t_list **instructions);



void	debug(t_dlist *stack_a, t_dlist *stack_b);

#endif
