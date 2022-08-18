/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:05:05 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/02 19:05:07 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lds)
{
	int		i;
	t_list	*lsd;

	lsd = lds;
	i = 0;
	while (lsd)
	{
		lsd = lsd->next;
		i++;
	}
	return (i);
}
