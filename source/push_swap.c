/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:37:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/24 22:17:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	return_error(void)
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

static void	init_stack_a(int argc, char **argv)
{
	int	number;
	t_list	*stack_a;
	int	i;

	i = 1;
	number = ft_atoi(argv[i]);
	stack_a = ft_lstnew(number);
	while (i < (argc - 1))
	{
		i++;
		number = ft_atoi(argv[i]);
		if (!(is_repeated(stack_a, number)))
			ft_lstadd_back(&stack_a, ft_lstnew(number));
		else
		{
			return_error();
		}
	}
	ft_lstiter(stack_a, &ft_putnbr);
}

static int	args_arent_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == NULL)
			return (1);
		i++;
	}
	return (0);
}

int	main (int argc, char **argv)
{
	if ((argc == 1) || args_arent_int(argc, argv))
	{
		ft_printf("eu");
		return_error();
	}
	init_stack_a(argc, argv);
	return (0);
}