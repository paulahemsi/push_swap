/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:37:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/31 16:43:47 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_repeated(t_dlist *lst, int number)
{
	t_dlist	*aux;

	if (lst == NULL)
		return (0);
	aux = lst;
	while (aux != NULL)
	{
		if ((int)aux->content == number)
			return (1);
		aux = aux->next;
	}
	return (0);
}

static void	init_stack_a(int argc, char **argv, t_dlist	**stack_a)
{
	int	number;
	int	i;

	i = 1;
	number = (int)ft_atoi(argv[i]);
	*stack_a = ft_dlstnew(number);
	while (i < (argc - 1))
	{
		i++;
		number = (int)ft_atoi(argv[i]);
		if (is_repeated(*stack_a, number))
			return_error();
		else
			ft_dlstadd_back(stack_a, ft_dlstnew(number));
	}
}

static void	check_if_args_are_integers(int argc, char **argv)
{
	int		i;
	int		j;
	double	number;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return_error();
			j++;
		}
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return_error();
		i++;
	}
}

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

//TODO opção da lista vir em variável de ambiente
int	main (int argc, char **argv)
{
	t_stack	stack;
	t_aux	aux;

	stack.a = NULL;
	stack.b = NULL;
	aux.instr = NULL;
	if (argc == 1)
		return_error();
	aux.total_num = argc - 1;
	check_if_args_are_integers(argc, argv);
	init_stack_a(argc, argv, &stack.a);
	aux.ordered_array = fill_ordered_array(stack.a, aux.total_num);
	aux.middle_num = aux.ordered_array[(aux.total_num / 2)];
	ft_printf("middle number: %i\n", aux.middle_num);
	lets_sort(&stack.a, &stack.b, &aux);
	ft_lstiter(aux.instr, &ft_putstr);
	ft_printf("--------total instructions: %i\n--------total numbers: %i\n", ft_lstsize(aux.instr), aux.total_num);
	ft_dlstiter(stack.a, &ft_putnbr);
	clear(&stack, &aux);
	return (0);
}
