/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:35:42 by mschempe          #+#    #+#             */
/*   Updated: 2018/06/13 12:41:10 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		k;

	if (ft_strlen(little) == '\0')
		return ((char *)big);
	i = -1;
	while (big[++i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (little[j])
			{
				if (little[j] != big[k])
					break ;
				j++;
				k++;
			}
			if (j == (int)ft_strlen(little))
				return ((char *)&big[i]);
		}
	}
	return (NULL);
}
