/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:05:15 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/16 18:43:45 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dv6ted4(t_fdf *fdf, t_bres *s, int *i0)
{
	int i;
	
	i = 0;
	while (i < s->dx_x)
	{
		put_pixel(fdf, i0[0], i0[1]);
		i++;
		i0[0] += s->x_inc;
		s->ex -= s->dy;
		if (s->ex < 0)
		{
			i0[1] += s->y_inc;
			s->ex += s->dx;
		}
	}
}

void	ep6dts(t_fdf *fdf, t_bres *s, int *i0)
{
	int i;
	
	i = 0;
	while (i < s->dy_x)
	{
		put_pixel(fdf, i0[0], i0[1]);
		i++;
		i0[1] += s->y_inc;
		s->ey -= s->dx;
		if (s->ey < 0)
		{
			i0[0] += s->x_inc;
			s->ey += s->dy;
		}
	}
}

void	select_engine(t_fdf *fdf, int *i0, int *i1)
{
	t_bres *s;

	s = (t_bres *)malloc(sizeof(t_bres));
	s->ex = abs(i1[0] - i0[0]);
	s->ey = abs(i1[1] - i0[1]);
	s->dx = 2 * s->ex;
	s->dy = 2 * s->ey;
	s->dx_x = s->ex;
	s->dy_x = s->ey;
	s->x_inc = 1;
	s->y_inc = 1;

	if (i0[0] > i1[0])
		s->x_inc = -1;
	if (i0[1] > i1[1])
		s->y_inc = -1;
	if (s->dx_x > s->dy_x)
		dv6ted4(fdf, s, i0);
	if (s->dx_x < s->dy_x)
		ep6dts(fdf, s, i0);
}

