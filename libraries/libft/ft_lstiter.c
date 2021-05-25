/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:39:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/24 22:05:26 by phemsi-a         ###   ########.fr       */
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
