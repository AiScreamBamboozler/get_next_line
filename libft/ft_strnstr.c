/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:44:44 by mschempe          #+#    #+#             */
/*   Updated: 2018/06/13 11:49:29 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = -1;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (little[j] && k < len)
			{
				if (little[j] != big[k])
					break ;
				j++;
				k++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
	}
	return (NULL);
}
