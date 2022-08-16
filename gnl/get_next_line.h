/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:24 by thomathi          #+#    #+#             */
/*   Updated: 2022/08/02 14:40:54 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../ft_printf/libft/srcs/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
/* void	ft_bzero_gnl(void *s, size_t n); */
/* void	*ft_calloc_gnl(size_t count, size_t size); */
/* char	*ft_strjoin_gnl(char *s1, char *s2); */
#endif
