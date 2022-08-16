/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:23:12 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/16 17:35:09 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/srcs/ft_printf.h"
# include "../ft_printf/libft/srcs/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define WIDTH 640 * 2
# define HEIGHT 480 * 2

typedef struct s_fdf
{
	int		**map;
	int		height;
	int		width;
	int		colors;
	int		fd;
	int		*mlx_ptr;
	int		*mlx_win;
	int		*img_ptr;
	char	*img_data;
	int		endian;
	int		bpp;
	int		line_length;
}	t_fdf;

typedef struct s_bres
{
	int	dx;
	int	dy;
	int	dx_x;
	int	dy_x;
	int	ex;
	int	ey;
	int x_inc;
	int y_inc;
}	t_bres;

void	fdf_errors(int err);
void	fdf_errors_open(char *file);
void	fdf_malloc_map(t_fdf *fdf);
void	fdf_co(t_fdf *fdf, char *file);
int		fdf_getinfos(int fd, int mode);
void	fdf_readmap(t_fdf *fdf);
void	put_pixel(t_fdf *fdf, int x, int y);
void	select_engine(t_fdf *fdf, int *i0, int *i1);
void	fdf_main(t_fdf *fdf);

#endif
