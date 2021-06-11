/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:39:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 11:08:23 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(int))
{
	t_dlist	*aux;

	if (lst == NULL)
		return ;
	aux = lst;
	while (aux != NULL)
	{
		f(aux->content);
		ft_putchar('\n');
		aux = aux->next;
	}
}

void	ft_dlstiter_reverse(t_dlist *lst, void (*f)(int))
{
	t_dlist	*aux;

	if (lst == NULL)
		return ;
	aux = lst;
	while (aux->next != NULL)
		aux = aux->next;
	while (aux != NULL)
	{
		f(aux->content);
		ft_putchar('\n');
		aux = aux->previous;
	}
}
