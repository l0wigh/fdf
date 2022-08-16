/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supfunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:58:40 by thomathi          #+#    #+#             */
/*   Updated: 2022/07/28 13:36:53 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = (char)ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*ft_utioa_loop(char *str, int len, unsigned long long n, int base)
{
	while (len-- > 0)
	{
		if (n % base > 9)
			str[len] = n % base + 'a' - 10;
		else
			str[len] = n % base + '0';
		n = n / base;
	}
	return (str);
}

char	*ft_uitoa_base(unsigned long long n, int base)
{
	char	*str;
	int		i;
	int		len;

	i = 1;
	len = 0;
	if (n == 0)
		len = 1;
	while (n / i != 0)
	{
		i *= base;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	str = ft_utioa_loop(str, len, n, base);
	return (str);
}
