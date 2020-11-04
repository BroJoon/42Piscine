/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:02:29 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 17:02:29 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_rush02.h"

int		deep_first_search(char *find, char **str, int row)
{
	int temp;

	temp = row;
	if ((row = ft_search(0, find, str, row)) < 0)
	{
		str = ft_free_2d(str, temp);
		return (-1);
	}
	return (row);
}

int		ft_deep_search_else(char *find, char **str, int row)
{
	char	c;
	int		temp;

	c = find[1];
	find[1] = '0';
	temp = row;
	if ((row = ft_search(0, find, str, row)) < 0)
	{
		str = ft_free_2d(str, temp);
		return (-1);
	}
	find[1] = c;
	if (c != '0')
		if ((row = input_dash(str, row)) < 0)
			return (row);
	find = ft_ignore_zero(find + 1);
	return (*find == '0' ? (row) : (select_search(find, str, row)));
}

int		div_search_more(char *find, char **str, int row)
{
	if (ft_strlen(find) > 3 && ft_strlen(find) % 3 == 0)
		return (ft_deep_search_0(find, str, row));
	else if (ft_strlen(find) == 3)
		return (ft_deep_search_3(find, str, row));
	return (ft_deep_search_else(find, str, row));
}

int		div_search_start(char *find, char **str, int row)
{
	char	*arr;

	if (ft_strlen(find) > 3 && ft_strlen(find) % 3 == 1)
	{
		if ((arr = (char *)malloc(sizeof(char) *
			(ft_strlen(find) + 1))) == NULL)
		{
			arr = ft_free(arr);
			str = ft_free_2d(str, row);
			return (-1);
		}
		return (ft_deep_search_1(arr, find, str, row));
	}
	else if (ft_strlen(find) > 3 && ft_strlen(find) % 3 == 2)
	{
		if ((arr = (char *)malloc(sizeof(char) * (ft_strlen(find)))) == NULL)
		{
			arr = ft_free(arr);
			str = ft_free_2d(str, row);
			return (-1);
		}
		return (ft_deep_search_2(arr, find, str, row));
	}
	return (div_search_more(find, str, row));
}
