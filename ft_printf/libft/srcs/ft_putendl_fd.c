/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:37:29 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/02 15:37:36 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	x;
	int	endl;

	x = 0;
	endl = '\n';
	if (!s || !fd)
		return ;
	while (s[x])
	{
		write(fd, &s[x], 1);
		x++;
	}
	write(fd, &endl, 1);
}
