/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deep_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:36:14 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 17:36:14 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_rush02.h"

int		ft_deep_search_0_1(char *find, char **str, int row)
{
	char	*arr;
	int		temp;

	if ((arr = (char *)malloc(sizeof(char) * (ft_strlen(find) + 1))) == NULL)
	{
		arr = ft_free(arr);
		str = ft_free_2d(str, row);
		return (-1);
	}
	arr[0] = '1';
	temp = 1;
	while (temp < ft_strlen(find))
		arr[temp++] = '0';
	arr[temp] = '\0';
	if ((row = deep_first_search(arr, str, row)) < 0)
	{
		arr = ft_free(arr);
		return (row);
	}
	arr = ft_free(arr);
	find = ft_ignore_zero(find + 1);
	return (*find == '0' ? (row) : (select_search(find, str, row)));
}

int		ft_deep_search_0(char *find, char **str, int row)
{
	char	c;

	c = find[1];
	find[1] = '\0';
	if ((row = deep_first_search(find, str, row)) < 0)
		return (row);
	if ((row = deep_first_search("100", str, row)) < 0)
		return (row);
	find[1] = c;
	if (find[1] == '0' && find[2] == '0')
		return (ft_deep_search_0_1(find + 2, str, row));
	else
	{
		find = ft_ignore_zero(find + 1);
		return (*find == '0' ? (row) : (select_search(find, str, row)));
	}
}

int		ft_deep_search_1(char *arr, char *find, char **str, int row)
{
	char	c;
	int		temp;

	c = find[1];
	find[1] = '\0';
	if ((row = deep_first_search(find, str, row)) < 0)
		return (row);
	find[1] = c;
	arr[0] = '1';
	temp = 1;
	while (temp < ft_strlen(find))
		arr[temp++] = '0';
	arr[temp] = '\0';
	if ((row = deep_first_search(arr, str, row)) < 0)
	{
		arr = ft_free(arr);
		return (row);
	}
	arr = ft_free(arr);
	find = ft_ignore_zero(find + 1);
	return (*find == '0' ? (row) : (select_search(find, str, row)));
}

int		ft_deep_search_2(char *arr, char *find, char **str, int row)
{
	char	c;
	int		temp;

	c = find[2];
	find[2] = '\0';
	if ((row = deep_first_search(find, str, row)) < 0)
		return (row);
	find[2] = c;
	arr[0] = '1';
	temp = 1;
	while (temp < ft_strlen(find) - 1)
		arr[temp++] = '0';
	arr[temp] = '\0';
	if ((row = deep_first_search(arr, str, row)) < 0)
	{
		arr = ft_free(arr);
		return (row);
	}
	arr = ft_free(arr);
	find = ft_ignore_zero(find + 2);
	return (*find == '0' ? (row) : (select_search(find, str, row)));
}

int		ft_deep_search_3(char *find, char **str, int row)
{
	char	c;

	c = find[1];
	find[1] = '\0';
	if ((row = deep_first_search(find, str, row)) < 0)
		return (row);
	if ((row = deep_first_search("100", str, row)) < 0)
		return (row);
	find[1] = c;
	find = ft_ignore_zero(find + 1);
	return (*find == '0' ? (row) : (select_search(find, str, row)));
}
