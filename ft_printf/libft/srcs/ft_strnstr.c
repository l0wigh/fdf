/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:58:28 by thomathi          #+#    #+#             */
/*   Updated: 2022/02/25 17:26:07 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	litlen;

	if (*little == '\0')
		return ((char *)big);
	litlen = ft_strlen(little);
	while (*big && n-- >= litlen)
	{
		if (*big == *little && ft_memcmp(big, little, litlen) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
