/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 02:08:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/25 11:28:00 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <stdio.h>

static int	atoi_isspace(int c)
{
	if (c == ' ' || c == '\v' || c == '\n'
		|| c == '\t' || c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}

double	ft_atoi(const char *nptr)
{
	double	number;
	int	sign;

	number = 0;
	sign = 1;
	while (atoi_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		number *= 10;
		number += (*nptr - '0');
		nptr++;
	}
	number *= sign;
	return (number);
}
