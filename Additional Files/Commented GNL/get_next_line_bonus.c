/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:28:39 by mschempe          #+#    #+#             */
/*   Updated: 2018/07/02 15:28:49 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_mem_free(char *str, char *i)
{
	char			*temp;

	temp = ft_strdup(i + (*i == '\n'));
	free(str);
	return (temp);
}

char	*find(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (&str[i]);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stat[1];
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!stat[fd])
		if (!(stat[fd] = ft_strnew(0)))
			return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(stat[fd], buff);
		free(stat[fd]);
		stat[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	temp = find(stat[fd]);
	*line = ft_strsub(stat[fd], 0, temp - stat[fd]);
	if (stat[fd][0] == '\0')
		return (0);
	stat[fd] = ft_mem_free(stat[fd], temp);
	return (1);
}
