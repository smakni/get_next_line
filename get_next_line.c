/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/06/01 17:36:53 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	lenc(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n' && str[i + 1] == '\n')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buffer[BUFF_SIZE + 1];
	static char		*tmp;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	if (!tmp && !(tmp = ft_memalloc(1)))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin_free(tmp, buffer);
		if (ft_memchr(buffer, '\n', BUFF_SIZE) != 0)
			break ;
	}
	if (!(*line = ft_memalloc(lenc(tmp) + 1)))
		return (-1);
	*line = ft_strncpy(*line, (const char *)tmp, lenc(tmp));
	tmp = ft_strsub_free(tmp, (lenc(tmp) + 1), (ft_strlen(tmp) - lenc(tmp)));
	if (ret < BUFF_SIZE && !ft_strlen(*line) && !ft_strlen(tmp))
	{
		ft_strdel(&(*line));
		return (0);
	}
	return (1);
}
