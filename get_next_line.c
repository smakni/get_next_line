/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:15:06 by smakni            #+#    #+#             */
/*   Updated: 2018/05/25 15:25:47 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len_line(char **line)
{
	int i;

	while (line[i] != '\n')
		i++;
	return (i);
}


int		get_next_line(const int fd, char **line)
{
	int		ret;
	int		len_line;
	char	buffer[BUFF_SIZE];
	char	*buff_line;
	
	len_line = ft_len_line(&line);
	buff_line = ft_memalloc(len_line);
	while (buff_line[len_line] != '\n')
	{
		ret = read(fd, buffer, BUFF_SIZE);
		ft_strcat(buff_line, buffer);
	}	
	printf("%s", buff_line);
	return (0);

}

int		main(int ac, char **av)
{
	int 	fd;
	char 	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, line);
	}
	else
		printf("ERROR");
	return (0);
}
