/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:24:39 by smakni            #+#    #+#             */
/*   Updated: 2018/06/05 11:45:49 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static void simple_string(int fd)
{
		char    *line;

        printf("gnl = %d\n", get_next_line(fd, &line));

        printf("gnl = %d\n", get_next_line(fd, &line));

        printf("gnl = %d\n", get_next_line(fd, &line));

        printf("gnl = %d\n", get_next_line(fd, &line));
}
*/

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;
	
	argc = 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		//ft_putstr("loop = ");
		//ft_putstr(line);
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
