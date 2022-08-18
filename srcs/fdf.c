/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:30:04 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/18 22:54:35 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_keyhook(int code, t_fdf *fdf)
{
	if (code == 53)
		fdf_exit_procedure(fdf);
	if (code == 8)
		fdf_colors(fdf);
	if (code >= 123 && code <= 126)
		fdf_map_move(fdf, code);
	if (code == 69 || code == 78)
		fdf_map_zoom(fdf, code);
	if (code == 36)
		fdf_debug(fdf);
	return (0);
}

void	fdf_initialize(t_fdf *fdf, char *file)
{
	fdf->mlx_ptr = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FdF");
	mlx_key_hook(fdf->mlx_win, fdf_keyhook, fdf);
	mlx_hook(fdf->mlx_win, 17, 0, fdf_exit_procedure, fdf);
	fdf->colors = malloc(sizeof(int) * 3);
	fdf->colors[0] = 0xc73067;
	fdf->colors[1] = 0x4169e1;
	fdf->colors[2] = 0xABADBABE;
	fdf->col_x = 0;
	fdf->terrain = 8;
	fdf->x_cor = 0;
	fdf->y_cor = 0;
	fdf->xx_cor = 1;
	fdf->xy_cor = 1;
	fdf->height = fdf_getinfos(fdf->fd, 1);
	fdf_co(fdf, file);
	fdf->width = fdf_getinfos(fdf->fd, 2);
	fdf_malloc_map(fdf);
	fdf_co(fdf, file);
	fdf_readmap(fdf);
}

int	fdf_check_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 'f')
		return (0);
	if (file[i - 2] != 'd')
		return (0);
	if (file[i - 3] != 'f')
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	if (argc != 2)
		fdf_errors(1);
	if (!fdf_check_extension(argv[1]))
		fdf_errors(2);
	fdf->fd = open(argv[1], O_RDONLY);
	if (fdf->fd == -1)
		fdf_errors_open(argv[1]);
	fdf_initialize(fdf, argv[1]);
	fdf_main(fdf);
	return (0);
}
