/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:09:42 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/18 14:43:29 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	fdf_colors(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_clear_window(fdf->mlx_ptr, fdf->mlx_win);
	if (fdf->col_x == 2)
		fdf->col_x = 0;
	else
		fdf->col_x++;
	fdf_main(fdf);
	return ;
}

void	fdf_map_move(t_fdf *fdf, int code)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_clear_window(fdf->mlx_ptr, fdf->mlx_win);
	if (code == 123)
		fdf->x_cor -= 20;
	else if (code == 124)
		fdf->x_cor += 20;
	else if (code == 125)
		fdf->y_cor += 20;
	else if (code == 126)
		fdf->y_cor -= 20;
	fdf_main(fdf);
	return ;
}

void	fdf_map_zoom(t_fdf *fdf, int code)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_clear_window(fdf->mlx_ptr, fdf->mlx_win);
	if (code == 69)
	{
		fdf->xx_cor++;
		fdf->xy_cor++;
	}
	if (code == 78)
	{
		fdf->xx_cor--;
		fdf->xy_cor--;
	}
	fdf_main(fdf);
}

void	fdf_map_terrain(t_fdf *fdf, int code)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_clear_window(fdf->mlx_ptr, fdf->mlx_win);
	if (code == 38)
		fdf->terrain--;
	if (code == 40)
		fdf->terrain++;
	fdf_main(fdf);
}
