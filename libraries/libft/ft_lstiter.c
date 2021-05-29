/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:39:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/28 09:31:36 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*aux;

	if (lst == NULL)
		return ;
	aux = lst;
	while (aux != NULL)
	{
		f(aux->content);
		//!tirar:
		ft_putchar('\n');
		//!
		aux = aux->next;
	}
}

void	ft_lstiter_reverse(t_list *lst, void (*f)(int))
{
	t_list	*aux;

	if (lst == NULL)
		return ;
	aux = lst;
	while (aux->next != NULL)
		aux = aux->next;
	while (aux != NULL)
	{
		f(aux->content);
		//!tirar:
		ft_putchar('\n');
		//!
		aux = aux->previous;
	}
}

