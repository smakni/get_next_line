/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/05/29 22:18:36 by sabri            ###   ########.fr       */
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
	printf("clear_read = %d\n", i);
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

static int 	nb_lines(const int fd)
{
	int 	i;
	int		 ret;
	char 	buffer[1];
	int 	count;

	
	i = 0;
	count = 0;
	while((ret = read(fd, buffer, 1)) > 0)
		if (ft_memchr(buffer, '\n', ret) == &buffer[i])
			count++;
		i++;
	printf("i = %d\n", count);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buffer[BUFF_SIZE + 1];
	static char		*tmp;
	static int		lines;

	if (!tmp)
		tmp = ft_memalloc(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		//if (ft_memchr(buffer, '\n', ret) != 0 && ft_memchr(tmp, '\0', ret))
		//	break ;
	}
	*line = ft_memalloc(len_line(tmp) + 1);
	*line = ft_strncpy(*line, (const char *)tmp, len_line(tmp));
	tmp = ft_strsub(tmp, (len_line(tmp) + 1), (ft_strlen(tmp) - len_line(tmp)));
	//tmp = clear_read(tmp);
	if (ret < BUFF_SIZE && !ft_strlen(tmp))
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
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
