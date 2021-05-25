/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:32:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/25 13:38:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*pointer;

	pointer = (t_list *)malloc(sizeof(t_list));
	if (!(pointer))
		return (NULL);
	pointer->content = content;
	pointer->next = NULL;
	pointer->previous = NULL;
	return (pointer);
}
