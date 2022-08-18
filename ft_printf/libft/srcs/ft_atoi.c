/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:15:16 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/03 18:35:43 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getfirstchar(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\n') || (nptr[i] == '\t')
		|| (nptr[i] == '\v') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	return (i++);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				neg;
	long long		res;

	neg = 1;
	res = 0;
	i = ft_getfirstchar(nptr);
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res < 0 && neg == 1)
			return (-1);
		if (res < 0 && neg == -1)
			return (0);
		res = (res * 10) + (nptr[i++] - '0');
	}
	return (res * neg);
}
