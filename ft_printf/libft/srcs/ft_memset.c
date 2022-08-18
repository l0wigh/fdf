/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:07:55 by thomathi          #+#    #+#             */
/*   Updated: 2022/02/25 16:58:37 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t d)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = b;
	while (i < d)
	{
		*p = c;
		p++;
		i++;
	}
	return (b);
}
