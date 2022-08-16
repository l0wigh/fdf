/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:58 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/02 14:21:30 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_bzero_gnl(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	int		i;

	i = -1;
	tab = (char *)malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero_gnl(tab, count * size);
	return (tab);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (s1[i])
		i++;
	while (s2[e])
		e++;
	tab = malloc(sizeof(char) * (i + e + 1));
	if (!tab)
		return (NULL);
	i = -1;
	e = 0;
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[e])
		tab[i++] = s2[e++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
