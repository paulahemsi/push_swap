/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:06:40 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/09 17:46:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"

# define LAST_CHUNCK	10

typedef struct s_stack
{
	t_dlist		*a;
	t_dlist		*b;
	t_list		*instr;
}				t_stack;

typedef struct s_stack_aux_a
{
	int			mid_index;
	int			higher_index;
	int			next_index_to_sort;
}				t_stack_aux_a;

typedef struct s_stack_aux_b
{
	int			mid_index;
	int			higher_index;
	int			lower_index;
}				t_stack_aux_b;

typedef struct s_aux
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
void	push(t_dlist **origin, t_dlist **dest, t_list **instr, char id);
/*
** sorting
*/
void	lets_sort(t_stack *stack, t_aux *aux);
void	small_sort(t_stack *stack, t_aux *aux, int total_numbers);
int		any_small_in_stack_a(t_dlist *stack_a, t_aux *aux);
void	send_half_to_b(t_stack *stack, t_aux *aux);
void	return_half_to_a(t_stack *stack, t_aux *aux, int limit);
void	start_sorting(t_stack *stack, t_aux *aux);
void	finish_sorting(t_stack *stack, t_aux *aux);
void	order_a(t_stack *stack, t_aux *aux);
/*
** aux
*/
void	quick_sort(int *array, int left, int right);
int		find_mid_index(int bigger_index, int smallest_index);
int		find_mid_index(int bigger_index, int smallest_index);
int		reverse_rotation_is_quicker(t_dlist *stack, int target_number);
int		rr_is_quick_mult(t_dlist *stack, int first_num, t_aux *aux);
void	rewind(t_dlist **stack_to_rewind);
void	fast_forward(t_dlist **stack_to_fast_forward);
void	reduce_instructions(t_list **instructions);
int		is_full(t_dlist *stack, int total_numbers);
int		is_sorted(t_dlist *stack);
int		last_num_index(t_dlist *stack);

#endif
