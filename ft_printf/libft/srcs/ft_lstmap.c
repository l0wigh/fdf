/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:56:50 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/02 20:56:50 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lsd, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lds;

	if (!lsd || !f)
		return (NULL);
	new = ft_lstnew(f(lsd->content));
	if (!new)
		return (NULL);
	lds = new;
	lsd = lsd->next;
	while (lsd)
	{
		lds->next = ft_lstnew(f(lsd->content));
		if (!lds->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lds = lds->next;
		lsd = lsd->next;
	}
	return (new);
}
