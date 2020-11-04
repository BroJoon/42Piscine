/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:35:10 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/04 17:07:26 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strstr(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(char *str, char *charset, int i)
{
	int		j;
har c	char	*dest;

	j = 0;
	while (str[i] && ft_strstr(str[i], charset) == 1)
	{
		i++;
		j++;
	}
	dest = (char *)malloc(sizeof(char) * (j + 1));
	i -= j;
	j = 0;
	while (str[i] && ft_strstr(str[i], charset) == 1)
		dest[j++] = str[i++];
	dest[j] = '\0';
	return (dest);
}

int		find_size(char *str, char *charset)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && ft_strstr(str[i], charset) == 0)
			i++;
		if (str[i] && ft_strstr(str[i], charset) == 1)
		{
			while (str[i] && ft_strstr(str[i], charset) == 1)
				i++;
			size++;
		}
	}
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	**split;

	i = 0;
	j = 0;
	size = find_size(str, charset);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	while (str[i])
	{
		while (str[i] && ft_strstr(str[i], charset) == 0)
			i++;
		if (str[i] && ft_strstr(str[i], charset) == 1)
		{
			split[j++] = ft_strdup(str, charset, i);
			while (str[i] && ft_strstr(str[i], charset) == 1)
				i++;
		}
	}
	split[j] = 0;
	return (split);
}
