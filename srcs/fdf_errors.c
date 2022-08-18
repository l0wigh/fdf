/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:33:34 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/18 22:22:11 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_errors(int err)
{
	if (err == 1)
		ft_printf("Mauvais nombre d'argument\n");
	if (err == 2)
		ft_printf("Mauvaise extension\n");
	if (err == 3)
	{
		ft_printf("La map n'est pas valide\n");
	}
	exit(0);
}

void	fdf_err_exit(t_fdf *fdf, int err)
{
	if (err == 1)
		ft_printf("La map n'est pas valide\n");
	fdf_exit_procedure_bis(fdf);
}

void	fdf_errors_open(char *file)
{
	ft_printf("Impossible d'ouvrir le fichier : %s\n", file);
	exit(0);
}
