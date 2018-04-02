/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 19:43:28 by imhaimou          #+#    #+#             */
/*   Updated: 2018/01/11 15:21:48 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_stock(char **r, char **line, char *buf)
{
	if (ft_strlen(*r) > 0)
	{
		*line = ft_strjoin(*r, buf);
		*r = NULL;
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char *r[MAX_FD];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (*line)
		*line = "";
	r[fd] = !r[fd] ? ft_strnew(1) : r[fd];
	while (!(ft_strchr(r[fd], '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
			return (ft_stock(&r[fd], line, buf));
		tmp = r[fd];
		r[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	*line = ft_strsub(r[fd], 0, ft_strchr(r[fd], '\n') - r[fd]);
	r[fd] = ft_strsub(r[fd], ft_strlen(*line) + 1, ft_strlen(r[fd]) \
		- ft_strlen(*line));
	return (r[fd] ? 1 : 0);
}

int main(int ac, char **av)
{
	int fd;
	int fd2;
	int fd3;
	int fd4;

	char *line;
	int i = 0;
	
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	fd4 = open(av[4], O_RDONLY);
	
	while (i++ < 10 && get_next_line(fd, &line) == 1)
	{
		printf("test %s\n", line);
	}
	printf("hello**********%d %s\n", get_next_line(fd2, &line), line);
	printf("%d %s\n",get_next_line(fd2, &line), line);
	printf("%d %s\n",get_next_line(fd2, &line), line);
	printf("%d %s\n",get_next_line(fd2, &line), line);
	printf("%d %s\n",get_next_line(fd3, &line), line);
	printf("%d %s\n",get_next_line(fd3, &line), line);
	printf("%d %s\n",get_next_line(fd3, &line), line);
	printf("%d %s\n",get_next_line(fd4, &line), line);
	printf("%d %s\n",get_next_line(fd4, &line), line);
	printf("%d %s\n",get_next_line(fd4, &line), line);
	printf("%d %s\n",get_next_line(fd, &line), line);
	printf("%d %s\n",get_next_line(fd, &line), line);
	printf("%d %s\n",get_next_line(fd, &line), line);
	printf("%d %s\n",get_next_line(fd, &line), line);
	printf("%d %s\n",get_next_line(fd2, &line), line);
	printf("%d %s\n",get_next_line(fd2, &line), line);
	printf("%d %s\n",get_next_line(fd3, &line), line);
	printf("%d %s\n",get_next_line(fd3, &line), line);
	printf("%d %s\n",get_next_line(fd3, &line), line);
	printf("%d %s\n",get_next_line(fd4, &line), line);
	printf("%d %s\n",get_next_line(fd4, &line), line);
	printf("%d %s\n",get_next_line(fd4, &line), line);
	printf("%d %s\n",get_next_line(fd2, &line), line);

	return (0); 
}
