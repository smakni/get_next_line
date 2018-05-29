/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/05/29 17:34:53 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *tmp, char *buffer)
{
	free(tmp);
	tmp = NULL;
	free(buffer);
	buffer = NULL;
}

int		len_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*buffer;
	static char		*tmp;

	if (!tmp)
		tmp = ft_memalloc(1);
	buffer = ft_memalloc(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_memchr(buffer, '\n', BUFF_SIZE) != 0)
			break ;
	}
	*line = ft_strtrim(ft_strdup((const char *)tmp));
	ft_free(tmp, buffer);
	if (ft_memchr(buffer, '\n', BUFF_SIZE) != 0)
		return (1);
	if (ret == 0)
		return (0);
	return (-1);
}

int		main(int ac, char **av)
{
	int 	fd;
	char 	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line (fd, &line) > 0)
			printf("line = %s", line);
	}
	else
		printf("ERROR");
	return (0);
}
