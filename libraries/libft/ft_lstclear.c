/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:31:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 13:06:59 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		del(aux);
		aux = temp;
	}
	*lst = NULL;
}
