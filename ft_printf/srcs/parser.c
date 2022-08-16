/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:46:12 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/10 11:46:12 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intparser(va_list arglist)
{
	int		argint;
	char	*argchar;
	int		counter;

	argint = va_arg(arglist, int);
	argchar = ft_itoa(argint);
	counter = (int)write(1, argchar, ft_strlen(argchar));
	free(argchar);
	return (counter);
}

int	ft_charparser(va_list arglist)
{
	char	*argchar;
	int		counter;

	counter = 0;
	argchar = va_arg(arglist, char *);
	if (argchar == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	counter += (int)write(1, argchar, ft_strlen(argchar));
	return (counter);
}

int	ft_uintparser(va_list arglist)
{
	unsigned int	arguint;
	char			*argchar;
	int				counter;

	arguint = va_arg(arglist, unsigned int);
	argchar = ft_uitoa(arguint);
	counter = (int)write(1, argchar, ft_strlen(argchar));
	free(argchar);
	return (counter);
}

int	ft_hexparser(va_list arglist, int mode)
{
	unsigned int	arguint;
	char			*argchar;
	int				counter;

	arguint = va_arg(arglist, unsigned int);
	if (mode == 1)
	{
		argchar = ft_itoa_base_x(arguint, 16, 1);
		write(1, argchar, ft_strlen(argchar));
	}
	else
	{
		argchar = ft_itoa_base_x(arguint, 16, 0);
		write(1, argchar, ft_strlen(argchar));
	}
	counter = (int) ft_strlen(argchar);
	free(argchar);
	return (counter);
}

int	ft_ifparser(const char *s, int charcount, va_list arglist)
{
	int	c;

	if (*s == 's')
		charcount += ft_charparser(arglist);
	else if (*s == 'd' || *s == 'i')
		charcount += ft_intparser(arglist);
	else if (*s == 'u')
		charcount += ft_uintparser(arglist);
	else if (*s == 'x')
		charcount += ft_hexparser(arglist, 0);
	else if (*s == 'X')
		charcount += ft_hexparser(arglist, 1);
	else if (*s == 'p')
		charcount += ft_ptrparser(arglist);
	else if (*s == 'c')
	{
		c = va_arg(arglist, int);
		charcount += write(1, &c, 1);
	}
	else if (*s == '%')
		charcount += write(1, "%", 1);
	return (charcount);
}
