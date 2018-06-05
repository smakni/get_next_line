/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/06/05 13:54:27 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	lenc(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != '\n')
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
	if (ret < BUFF_SIZE && !ft_strlen(tmp))
		return (0);
	if (!(*line = ft_memalloc(lenc(tmp) + 1)))
		return (-1);
	*line = ft_strncpy(*line, (const char *)tmp, lenc(tmp));
	tmp = ft_strsub_free(tmp, lenc(tmp) + 1, (ft_strlen(tmp) - lenc(tmp)));
	return (1);
}
