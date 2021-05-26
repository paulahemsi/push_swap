/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:37:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/25 22:45:25 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	return_error(void)
{
	ft_putendl("Error");
	exit(1);
}

static int	is_repeated(t_list *lst, int number)
{
	t_list	*aux;

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

static void	init_stack_a(int argc, char **argv, t_list	**stack_a)
{
	int	number;
	int	i;

	i = 1;
	number = (int)ft_atoi(argv[i]);
	*stack_a = ft_lstnew(number);
	while (i < (argc - 1))
	{
		i++;
		number = (int)ft_atoi(argv[i]);
		if (is_repeated(*stack_a, number))
			return_error();
		else
			ft_lstadd_back(stack_a, ft_lstnew(number));
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

int	main (int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return_error();
	check_if_args_are_integers(argc, argv);
	init_stack_a(argc, argv, &stack_a);
	return (0);
}
