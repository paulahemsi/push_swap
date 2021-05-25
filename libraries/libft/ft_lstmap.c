/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:48:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/24 21:47:06 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int))
{
	t_list	*new_list;
	t_list	*temp;

	new_list = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			if (new_list != NULL)
			{
				ft_lstclear(&new_list, del);
			}
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
