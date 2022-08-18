/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:49:33 by thomathi          #+#    #+#             */
/*   Updated: 2022/02/25 12:32:17 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_c;
	const unsigned char	*src_c;

	if (!dst && !src)
		return (0);
	dst_c = dst;
	src_c = src;
	while (n-- > 0)
		*dst_c++ = *src_c++;
	return (dst);
}
