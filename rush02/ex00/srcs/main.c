/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:04:01 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 06:52:07 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_check_find(char *find)
{
	int idx;

	if ((find[0] >= '0' && find[0] <= '9') != 1)
		return (-1);
	idx = 1;
	while (find[idx])
	{
		if ((find[idx] >= '0' && find[idx] <= '9') != 1)
			return (-1);
		idx++;
	}
	return (0);
}

char	*ft_ignore_zero(char *find)
{
	if (*find == '0' && (*(find + 1) >= '0' && *(find + 1) <= '9'))
		return (ft_ignore_zero(find + 1));
	return (find);
}

int		ft_default_dict(char *find)
{
	if (find[0] == '+')
		find++;
	if (ft_check_find(find) < 0)
		return (-1);
	find = ft_ignore_zero(find);
	return (ft_start(find, "dictionary/numbers.dict"));
}

int		ft_user_dict(char *fn, char *find)
{
	if (find[0] == '+')
		find++;
	if (ft_check_find(find) < 0)
		return (-1);
	find = ft_ignore_zero(find);
	return (ft_start(find, fn));
}

int		main(int argc, char *argv[])
{
	int check;

	check = 0;
	if (argc != 2 && argc != 3)
	{
		ft_puterror();
		return (-1);
	}
	else if (argc == 2)
		check = ft_default_dict(argv[1]);
	else if (argc == 3)
		check = ft_user_dict(argv[1], argv[2]);
	if (check < 0)
	{
		check == -1 ? ft_puterror() : ft_dicerror();
		return (-1);
	}
	return (0);
}
