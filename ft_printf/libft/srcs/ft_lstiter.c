/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:40:19 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/02 20:40:19 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lsd, void (*f)(void *))
{
	if (!lsd || !f)
		return ;
	while (lsd)
	{
		f(lsd->content);
		lsd = lsd->next;
	}
}
