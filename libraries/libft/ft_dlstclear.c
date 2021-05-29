/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:31:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 12:53:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*aux;
	t_dlist	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}
