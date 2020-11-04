/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:33:44 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/02 10:24:55 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *dest)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	return (i);
}

int		str_cat(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	return (n + i);
}

void	strs_cat(char *str_join, char **strs, char *sep, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = str_cat(str_join, strs[i], j);
		if (i < size - 1)
			j = str_cat(str_join, sep, j);
		i++;
	}
	str_join[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str_join;

	i = 0;
	if (size == 0)
	{
		str_join = (char *)malloc(sizeof(char) * 1);
		str_join[0] = 0;
		return (str_join);
	}
	len = str_len(sep) * (size - 1);
	while (i < size)
	{
		len += str_len(strs[i]);
		i++;
	}
	str_join = (char *)malloc(sizeof(char) * (len + 1));
	strs_cat(str_join, strs, sep, size);
	return (str_join);
}
