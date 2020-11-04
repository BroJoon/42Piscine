/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:24:32 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 19:24:32 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "ft_rush02.h"

int		ft_is_find(int fd, char *find, char **str, int row)
{
	char	c;

	if (read(fd, &c, 1) == 0 && find[1] == '\0')
	{
		str = ft_free_2d(str, row);
		close(fd);
		return (-2);
	}
	if (read(fd, &c, 1) == 0)
	{
		close(fd);
		return (div_search_start(find, str, row));
	}
	close(fd);
	row = ft_save_str(0, str, row, ft_current_buf(find, str, 0));
	if (row < 0)
		return (row);
	return (row);
}

int		ft_is_equal(int fd, int idx)
{
	char c;

	if (idx > 0)
	{
		read(fd, &c, 1);
		if (c != ':' && c != ' ')
			while (read(fd, &c, 1))
				;
	}
	return (0);
}

int		ft_search(int fd, char *find, char **str, int row)
{
	int		idx;
	char	c;

	if ((fd = open(g_fn, O_RDONLY)) < 0)
	{
		close(fd);
		str = ft_free(str);
		return (-2);
	}
	idx = 0;
	while (find[idx] && read(fd, &c, 1))
	{
		if (c == find[idx])
			idx++;
		else
		{
			idx = 0;
			while (read(fd, &c, 1))
				if (c == '\n')
					break ;
		}
	}
	if ((idx = ft_is_equal(fd, idx)) < 0)
		return (idx);
	return (ft_is_find(fd, find, str, row));
}

int		select_search(char *find, char **str, int row)
{
	char *temp;

	temp = 0;
	if (ft_strlen(find) >= 3)
		temp = ft_ignore_zero(find + 1);
	if (ft_strlen(find) >= 3 && *temp == '0')
		return (div_search_start(find, str, row));
	else
		return (ft_search(0, find, str, row));
}

int		ft_start(char *find, char *fn)
{
	int		check_n_row;
	char	**str;

	g_fn = fn;
	if ((str = (char **)malloc(sizeof(char *) * ft_strlen(find) * 2)) == NULL)
	{
		str = ft_free(str);
		return (-1);
	}
	if ((check_n_row = select_search(find, str, 0)) < 0)
		return (check_n_row);
	check_n_row = ft_end(str, check_n_row);
	return (check_n_row);
}
