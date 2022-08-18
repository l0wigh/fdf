/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:53:44 by thomathi          #+#    #+#             */
/*   Updated: 2022/02/25 12:34:14 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_c;
	const unsigned char	*src_c;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		dst_c = dst + n;
		src_c = src + n;
		while (n-- > 0)
		{
			*--dst_c = *--src_c;
		}
	}
	else
	{
		dst_c = dst;
		src_c = src;
		while (n-- > 0)
			*dst_c++ = *src_c++;
	}
	return (dst);
}
