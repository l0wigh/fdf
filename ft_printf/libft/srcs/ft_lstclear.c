/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:22:34 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/02 20:22:34 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lsd, void (*del)(void *))
{
	t_list	*lds;

	if (lsd)
	{
		while (*lsd)
		{
			lds = (*lsd)->next;
			ft_lstdelone(*lsd, del);
			(*lsd) = lds;
		}
	}
}
