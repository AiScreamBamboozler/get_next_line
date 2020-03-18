/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:29:07 by mschempe          #+#    #+#             */
/*   Updated: 2018/06/16 16:29:53 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_words(char const *s, char c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i])
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static size_t	word_len(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * num_words(s, c) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			str[cnt] = ft_strsub(s, i, word_len(&s[i], c));
			cnt++;
			i += word_len(&s[i], c);
		}
		while (s[i] && s[i] == c)
			i++;
	}
	str[cnt] = NULL;
	return (str);
}
