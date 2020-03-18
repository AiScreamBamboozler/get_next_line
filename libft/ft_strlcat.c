/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:17:01 by mschempe          #+#    #+#             */
/*   Updated: 2018/06/13 11:23:05 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	res;

	i = 0;
	j = ft_strlen(dst);
	res = ft_strlen(src) + j;
	if (size <= (size_t)j)
		return (ft_strlen(src) + size);
	while (src[i] && (size > (size_t)j + 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (res);
}
