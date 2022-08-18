/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:47 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/18 22:51:43 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_malloc_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->map = malloc(fdf->height * sizeof(int *));
	while (i < fdf->height)
	{
		fdf->map[i] = malloc(fdf->width * sizeof(int));
		i++;
	}
	return ;
}

int	fdf_getinfos(int fd, int mode)
{
	int		i;
	char	*line;
	char	**line_elem;

	i = 0;
	line = get_next_line(fd);
	if (mode == 1)
	{
		while (line)
		{
			line = get_next_line(fd);
			i++;
		}
	}
	else
	{
		line_elem = ft_split(line, ' ');
		while (line_elem && line_elem[i])
			i++;
	}
	return (i);
}

int	fdf_readmap_loop(t_fdf *fdf, char **line_elem, int y)
{
	int	x;

	x = 0;
	while (line_elem[x])
	{
		if (x > fdf->width)
			fdf_err_exit(fdf, 1);
		fdf->map[y][x] = ft_atoi(line_elem[x]);
		x++;
	}
	return (x);
}	

void	fdf_readmap(t_fdf *fdf)
{
	int		x;
	int		y;
	char	*line;
	char	**line_elem;

	x = 0;
	y = 0;
	line = get_next_line(fdf->fd);
	line_elem = ft_split(line, ' ');
	while (line)
	{
		if (y > fdf->height)
			fdf_err_exit(fdf, 1);
		x = fdf_readmap_loop(fdf, line_elem, y);
		if (x < fdf->width)
			fdf_err_exit(fdf, 1);
		y++;
		x = 0;
		line = get_next_line(fdf->fd);
		line_elem = ft_split(line, ' ');
	}
	if (y < fdf->height)
		fdf_err_exit(fdf, 1);
	return ;
}

void	fdf_co(t_fdf *fdf, char *file)
{
	close(fdf->fd);
	fdf->fd = open(file, O_RDONLY);
}
