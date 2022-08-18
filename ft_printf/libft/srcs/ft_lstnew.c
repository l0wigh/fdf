/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:35:33 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/02 18:35:37 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lds;

	lds = (t_list *) malloc(sizeof(*lds));
	if (!lds)
		return (NULL);
	lds->content = content;
	lds->next = NULL;
	return (lds);
}
