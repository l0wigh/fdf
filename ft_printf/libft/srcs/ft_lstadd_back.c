/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:01:48 by thomathi          #+#    #+#             */
/*   Updated: 2022/03/07 12:34:51 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lsd, t_list *n)
{
	t_list	*lds;

	if (lsd)
	{
		if (*lsd == NULL)
			*lsd = n;
		else
		{
			lds = ft_lstlast(*(lsd));
			lds->next = n;
		}
	}
}
