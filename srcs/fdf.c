/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:30:04 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/16 18:27:54 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_initialize(t_fdf *fdf, char *file)
{
	fdf->mlx_ptr = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FdF");
	fdf->colors = 0x00ff00;
	fdf->terrain = 2;
	fdf->height = fdf_getinfos(fdf->fd, 1);
	fdf_co(fdf, file);
	fdf->width = fdf_getinfos(fdf->fd, 2);
	fdf_malloc_map(fdf);
	fdf_co(fdf, file);
	fdf_readmap(fdf);
}

int	fdf_check_extension(char *file)
{
	int i;

	i = ft_strlen(file);
	if (file[i - 1] != 'f')
		return (0);
	if (file[i - 2] != 'd')
		return (0);
	if (file[i - 3] != 'f')
		return (0);
	return (1);
}

int main(int argc, char *argv[])
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
