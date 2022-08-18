/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:23:12 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/18 19:31:32 by thomathi         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 960
/* # define ISOX 24 */
/* # define ISOY 9 */
# define ISOX 31
# define ISOY 16

typedef struct s_fdf
{
	int		**map;
	int		height;
	int		width;
	int		*colors;
	int		col_x;
	int		fd;
	int		terrain;
	int		x_cor;
	int		y_cor;
	int		xx_cor;
	int		xy_cor;
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
void	put_pixel(t_fdf *fdf, int x, int y, int c);
void	select_engine(t_fdf *fdf, int *i0, int *i1);
void	fdf_main(t_fdf *fdf);
int		fdf_exit_procedure(t_fdf *fdf);
void	fdf_colors(t_fdf *fdf);
void	fdf_map_move(t_fdf *fdf, int code);
void	fdf_map_zoom(t_fdf *fdf, int code);
void	fdf_map_terrain(t_fdf *fdf, int code);
void	fdf_debug(t_fdf *fdf);

#endif
