/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:38:29 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/04 06:23:31 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * len + 1);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *strs;
	int			i;

	i = 0;
	strs = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (strs == 0)
		return (0);
	while (i < ac)
	{
		strs[i].str = av[i];
		strs[i].size = ft_strlen(av[i]);
		strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	strs[i].str = 0;
	return (strs);
}
