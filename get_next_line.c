/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/05/29 19:28:23 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		len_line(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char 	*clear_read(char *str)
{
	int 	i;
	int		j;
	char 	*new;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new = ft_memalloc(ft_strlen(str) - i);
	if (str[i] == '\n')
		i++;
	while (str[i])
	{	
		new[j] = str[i];
		i++;
		j++;
	}
	new[j] = '\0';
	ft_strdel(&str);
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buffer[BUFF_SIZE + 1];
	static char		*tmp;

	if (!tmp)
		tmp = ft_memalloc(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_memchr(buffer, '\n', ret) != 0)
			break ;
	}
	*line = ft_memalloc(len_line(tmp) + 1);
	*line = ft_strncpy(*line, (const char *)tmp, len_line(tmp));
	tmp = clear_read(tmp);
	if (ret < BUFF_SIZE && !ft_strlen(tmp))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	argc = 0;
	line = 0;
	ret = 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
