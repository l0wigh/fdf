/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:21:23 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/04 15:27:54 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t l)
{
	size_t	dstl;
	size_t	srcl;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (dstl >= l)
		dstl = l;
	if (dstl == l)
		return (srcl + l);
	if (srcl < l - dstl)
	{
		ft_memcpy(dst + dstl, src, srcl);
		dst[dstl + srcl] = '\0';
	}
	else
	{
		ft_memcpy(dst + dstl, src, l - dstl - 1);
		dst[l - 1] = '\0';
	}
	return (dstl + srcl);
}
