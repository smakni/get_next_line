/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/05/25 16:33:33 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		ret;
	char	*buffer;
	char	tmp;
	
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[BUFF_SIZE + 1] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_memchr(buffer, '\n', BUFF_SIZE) != 0)
			break ;
	}
	//ft_memcpy(line, tmp, ft_strlen((const char *)tmp));
	printf("line = %s", tmp);
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
