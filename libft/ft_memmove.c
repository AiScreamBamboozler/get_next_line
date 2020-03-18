/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:34:54 by mschempe          #+#    #+#             */
/*   Updated: 2018/06/12 14:22:50 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcc;
	char	*dstc;
	size_t	i;
	size_t	n;

	n = len - 1;
	i = 0;
	srcc = (char *)src;
	dstc = (char *)dst;
	if (srcc < dstc)
		while ((int)n >= 0)
		{
			dstc[n] = srcc[n];
			n--;
		}
	else
		while (i < len)
		{
			dstc[i] = srcc[i];
			i++;
		}
	return (dst);
}
