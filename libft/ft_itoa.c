/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:31:25 by mschempe          #+#    #+#             */
/*   Updated: 2018/06/16 16:32:28 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	int		temp;
	int		len;
	int		neg;
	char	*str;

	temp = nbr;
	len = 2;
	neg = (nbr < 0) ? 1 : 0;
	while (temp /= 10)
		len++;
	len = len + neg;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
