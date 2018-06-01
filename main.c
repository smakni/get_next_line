/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:24:39 by smakni            #+#    #+#             */
/*   Updated: 2018/06/01 17:44:48 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void simple_string(int fd)
{
		char    *line;

        printf("gnl = %d\n", get_next_line(fd, &line));

        printf("gnl = %d\n", get_next_line(fd, &line));

        printf("gnl = %d\n", get_next_line(fd, &line));

        printf("gnl = %d\n", get_next_line(fd, &line));
}

int		main(int argc, char **argv)
{
	int		fd;

	argc = 0;
	fd = open(argv[1], O_RDONLY);
	simple_string(fd);
	/*while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}*/
	return (0);
}
