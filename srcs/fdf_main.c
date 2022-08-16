/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:50:04 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/16 18:28:35 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y)
{
	char	*addr;
 
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		fdf->img_data = mlx_get_data_addr(fdf->img_ptr \
				, &fdf->bpp, &fdf->line_length, &fdf->endian);
		addr = fdf->img_data + (y * fdf->line_length + x * (fdf->bpp / 8));
		*(unsigned int *)addr = fdf->colors;
	}
}

void	fdf_bresenham_dv6ted4(t_fdf *fdf, int x, int y)
{
	int *i0;
	int *i1;

	i0 = malloc(sizeof(int) * 3);
	i1 = malloc(sizeof(int) * 3);

	i0[2] = fdf->map[y][x] * fdf->terrain;
	i0[0] = (WIDTH / 3) + (x - y) * 24;
	i0[1] = (HEIGHT / 3) + (x + y) * 9 - i0[2];
	x++;
	i1[2] = fdf->map[y][x] * fdf->terrain;
	i1[0] = (WIDTH / 3) + (x - y) * 24;
	i1[1] = (HEIGHT / 3) + (x + y) * 9 - i1[2];
	select_engine(fdf, i0, i1);
}

void	fdf_bresenham_ep6dts(t_fdf *fdf, int x, int y)
{
	int *i0;
	int *i1;

	i0 = malloc(sizeof(int) * 3);
	i1 = malloc(sizeof(int) * 3);

	i0[2] = fdf->map[y][x];
	i0[2] = fdf->map[y][x] * fdf->terrain;
	i0[0] = (WIDTH / 3) + (x - y) * 24;
	i0[1] = (HEIGHT / 3) + (x + y) * 9 - i0[2];
	y++;
	i1[2] = fdf->map[y][x] * fdf->terrain;
	i1[0] = (WIDTH / 3) + (x - y) * 24;
	i1[1] = (HEIGHT / 3) + (x + y) * 9 - i1[2];
	select_engine(fdf, i0, i1);
}

void	fdf_main(t_fdf *fdf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	while (y < fdf->height - 1)
	{
		while (x < fdf->width)
		{
			fdf_bresenham_dv6ted4(fdf, x, y);
			fdf_bresenham_ep6dts(fdf, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->mlx_win, fdf->img_ptr, 0, 0);
	mlx_loop(fdf->mlx_ptr);
}
