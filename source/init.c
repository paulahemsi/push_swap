/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:57:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/06 15:48:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*fill_ordered_array(t_dlist *stack_a, int total)
{
	int	*ordered_array;
	int	i;

	ordered_array = (int *)malloc(total * sizeof(int));
	if (!ordered_array)
		return_error();
	i = 0;
	while (i < total)
	{
		ordered_array[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	quick_sort(ordered_array, 0, (total - 1));
	return (ordered_array);
}

static int	find_index(t_stack *stack, t_aux *aux, int index)
{
	if (aux->ordered_array[index] == stack->a->content)
		return (index);
	return (find_index(stack, aux, (index + 1)));
}

static void	fill_stack_indexes(t_stack *stack, t_aux *aux)
{
	if (stack->a->next == NULL)
	{
		stack->a->index = find_index(stack, aux, 0);
		rewind(&stack->a);
		return ;
	}
	stack->a->index = find_index(stack, aux, 0);
	stack->a = stack->a->next;
	fill_stack_indexes(stack, aux);
}

static void	init_aux(t_dlist *stack_a, t_aux *aux, int argc)
{
	ft_memset(aux, 0, sizeof(*aux));
	aux->total_num = argc - 1;
	aux->ordered_array = fill_ordered_array(stack_a, aux->total_num);
	aux->a.higher_index = aux->total_num - 1;
	aux->a.next_index_to_sort = 0;
	aux->a.mid_index = find_mid_index(aux->a.higher_index,
			aux->a.next_index_to_sort);
}

void	init(t_stack *stack, t_aux *aux, int argc, char **argv)
{
	init_stack_a(argc, argv, &stack->a);
	init_aux(stack->a, aux, argc);
	fill_stack_indexes(stack, aux);
}
