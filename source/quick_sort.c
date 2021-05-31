/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:14:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/31 13:16:06 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int partition(int *array, int left, int right)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	pivot = array[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[j];
			array[j] = array[i]; 
			array[i] = temp;
		}
		j++;
	}
	temp = array[left];
	array[left] = array[i]; 
	array[i] = temp;
	return (i);
}

void	quick_sort(int *array, int left, int right)
{
	int	index_pivot;

	if (left < right)
	{
		index_pivot = partition(array, left, right);
		quick_sort(array, left, index_pivot - 1);
		quick_sort(array, index_pivot + 1, right);
	}
}