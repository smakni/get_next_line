/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/05/28 23:53:11 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	len_line(char *file)
{
	int i;
	
	i = 0;
	while(file[i])
		i++;
	return (i);
}


int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buffer;
	char		*tmp;
	static int 	i;

	i = 0;
	tmp = ft_memalloc(1);
	buffer = ft_memalloc(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[BUFF_SIZE + 1] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_memchr(buffer, '\n', BUFF_SIZE) != 0)
			break ;
	}
	line[i] = ft_memalloc(ft_strlen((const char *)tmp));
	ft_memcpy(line[i], tmp, ft_strlen((const char *)tmp));
	printf("line = %s", line[i]);
	return (0);
}

int		main(int ac, char **av)
{
	int 	fd;
	char 	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
	}
	else
		printf("ERROR");
	return (0);
}
