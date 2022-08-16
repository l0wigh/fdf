/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:17:10 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/10 12:17:10 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int				charcount;
	va_list			arglist;
	int				i;

	i = -1;
	charcount = 0;
	va_start(arglist, s);
	while (s[++i])
	{
		if (s[i] == '%')
			charcount = ft_ifparser((s + ++i), charcount, arglist);
		else
			charcount += (int) write(1, &s[i], 1);
	}
	va_end(arglist);
	return (charcount);
}
