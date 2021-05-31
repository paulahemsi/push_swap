/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:37:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/31 13:06:23 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	return_error(void)
{
	ft_putendl("Error");
	exit(1);
}

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

static int partition(int *ordered_array, int left, int right)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	pivot = ordered_array[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (ordered_array[j] < pivot)
		{
			i++;
			temp = ordered_array[j];
			ordered_array[j] = ordered_array[i]; 
			ordered_array[i] = temp;
		}
		j++;
	}
	temp = ordered_array[left];
	ordered_array[left] = ordered_array[i]; 
	ordered_array[i] = temp;
	return (i);
}

static void	quick_sort(int *ordered_array, int left, int right)
{
	int	index_pivot;

	if (left < right)
	{
		index_pivot = partition(ordered_array, left, right);
		quick_sort(ordered_array, left, index_pivot - 1);
		quick_sort(ordered_array, index_pivot + 1, right);
	}
}

static void	fill_ordered_array(t_dlist *stack_a, int total)
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
	i = 0;
	ft_putendl("antes do quick sort:");
	while (i < total)
	{
		ft_printf("%i ", ordered_array[i]);
		i++;
	}
	ft_putchar('\n');
	quick_sort(ordered_array, 0, (total - 1));
	i = 0;
	ft_putendl("depois do quick sort:");
	while (i < total)
	{
		ft_printf("%i ", ordered_array[i]);
		i++;
	}
	ft_putchar('\n');
}

//TODO opção da lista vir em variável de ambiente
int	main (int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	t_list	*instr;

	stack_a = NULL;
	stack_b = NULL;
	instr = NULL;
	if (argc == 1)
		return_error();
	check_if_args_are_integers(argc, argv);
	init_stack_a(argc, argv, &stack_a);
	fill_ordered_array(stack_a, (argc - 1));
	lets_sort(&stack_a, &stack_b, (argc - 1), &instr);
	ft_lstiter(instr, &ft_putstr);
	ft_putnbr(ft_lstsize(instr));
	ft_dlstclear(&stack_a);
	ft_dlstclear(&stack_b);
	ft_lstclear(&instr, &free);
	return (0);
}
