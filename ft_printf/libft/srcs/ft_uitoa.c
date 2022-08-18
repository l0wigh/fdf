/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:28:02 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/08 13:27:30 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getstr(char *str, unsigned int nbr, size_t len)
{
	while (nbr > 0)
	{
		*(str + len--) = nbr % 10 + '0';
		nbr /= 10;
	}
	return (len);
}

static size_t	ft_getlen(unsigned int n, size_t len)
{
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	size_t			len;
	char			*str;
	unsigned int	nbr;

	nbr = n;
	len = ft_getlen(n, 0);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	*(str + len--) = '\0';
	len = ft_getstr(str, nbr, len);
	*(str + len) = '0';
	return (str);
}
