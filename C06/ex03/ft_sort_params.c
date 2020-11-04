/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:01:48 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/04 17:10:38 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	if (s1[i] != '\0')
		return (1);
	return (-1);
}

void	print(int argc, char *argv[])
{
	int j;
	int i;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	j = 1;
	while (j < argc)
	{
		i = j + 1;
		while (i < argc)
		{
			if (ft_strcmp(argv[j], argv[i]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			i++;
		}
		j++;
	}
	print(argc, argv);
	return (0);
}
