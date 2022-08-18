/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:50:56 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/02 19:50:56 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lsd)
{
	while (lsd)
	{
		if (!lsd->next)
			return (lsd);
		lsd = lsd->next;
	}
	return (lsd);
}
