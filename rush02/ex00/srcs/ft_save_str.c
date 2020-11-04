/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:41:28 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 19:32:05 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_rush02.h"

int		ft_open_and_read(char **str, int row, int buf)
{
	int		fd;
	char	c[buf + 1];

	if ((fd = open(g_fn, O_RDONLY)) < 0)
	{
		str = ft_free_2d(str, row);
		close(fd);
		return (-2);
	}
	read(fd, c, buf);
	return (fd);
}

int		ft_find_printable(int fd, char **str, int row, int buf)
{
	char c;

	while (read(fd, &c, 1) && buf++)
	{
		if (c == '\n')
		{
			str = ft_free_2d(str, row);
			close(fd);
			return (-2);
		}
		if (c == ':')
			break ;
	}
	while (read(fd, &c, 1) && buf++)
	{
		if (c == '\n')
		{
			str = ft_free_2d(str, row);
			close(fd);
			return (-2);
		}
		if ((c >= 33 && c <= 126))
			break ;
	}
	return (buf - 1);
}

int		ft_file_strlen(int fd)
{
	int		len;
	char	c;

	len = 0;
	while (len += read(fd, &c, 1))
		if (c == '\n')
			break ;
	close(fd);
	return (len);
}

int		ft_save_str(int fd, char **str, int row, int buf)
{
	int		len;

	fd = ft_open_and_read(str, row, buf);
	if ((buf = ft_find_printable(fd, str, row, buf)) < 0)
	{
		str = ft_free_2d(str, row);
		close(fd);
		return (-2);
	}
	close(fd);
	fd = ft_open_and_read(str, row, buf);
	len = ft_file_strlen(fd);
	if ((str[row] = (char *)malloc(sizeof(char) * len)) == NULL)
	{
		str = ft_free_2d(str, row);
		return (-1);
	}
	fd = ft_open_and_read(str, row, buf);
	read(fd, str[row], len - 1);
	str[row][len - 1] = '\0';
	return (row + 1);
}
