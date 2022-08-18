/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:29:45 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/18 22:53:52 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_debug(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->height)
	{
		while (x < fdf->width)
		{
			ft_printf("%d ", fdf->map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
		x = 0;
	}
}
