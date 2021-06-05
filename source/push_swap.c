/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:37:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/05 19:07:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

//TODO opção da lista vir em string
int	main (int argc, char **argv)
{
	t_stack	stack;
	t_aux	aux;

	stack.a = NULL;
	stack.b = NULL;
	if (argc == 1)
		return_error();
	check_if_args_are_integers(argc, argv);
	init(&stack, &aux, argc, argv);
	lets_sort(&stack, &aux);
	ft_lstiter(aux.instr, &ft_putstr);
	ft_dlstiter(stack.a, &ft_putnbr);
	ft_printf("--------total instructions: %i\n--------total numbers: %i\n", ft_lstsize(aux.instr), aux.total_num);
	clear(&stack, &aux);
	return (0);
}
