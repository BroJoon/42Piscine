/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:18:25 by jpyo              #+#    #+#             */
/*   Updated: 2020/10/31 22:41:05 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "ft_rush02.h"

#include <stdio.h>

int		ft_current_buf(char *find, char **str, int len)
{
	int		fd;
	int		idx;
	char	c;

	if ((fd = open(g_fn, O_RDONLY)) < 0)
	{
		close(fd);
		str = ft_free(str);
		return (-2);
	}
	idx = 0;
	len = 1;
	while (find[idx] && read(fd, &c, 1) && len++)
	{
		if (c == find[idx])
			idx++;
		else
		{
			idx = 0;
			while (read(fd, &c, 1) && len++)
				if (c == '\n')
					break ;
		}
	}
	return (len - 1);
}
