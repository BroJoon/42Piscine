/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:24:03 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 19:27:57 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_rush02.h"

void	ft_print(char **str, int row)
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (j > 0 && str[i][j] == ' ')
				if (str[i][j - 1] == ' ')
				{
					j++;
					continue ;
				}
			write(1, &str[i][j++], 1);
		}
		if (i != row - 1 && str[i + 1][0] == '-' && str[i + 1][1] == 0)
			write(1, &str[i++ + 1][0], 1);
		else if (i != row - 1)
			write(1, " ", 1);
		i++;
	}
}

int		ft_end(char **str, int row)
{
	if (row >= 0)
		ft_print(str, row);
	str = ft_free_2d(str, row);
	return (row);
}
