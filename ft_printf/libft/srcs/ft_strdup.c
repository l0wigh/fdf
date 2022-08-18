/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:50:26 by thomathi          #+#    #+#             */
/*   Updated: 2022/02/25 17:50:49 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s, ft_strlen(s) + 1);
	return (p);
}
