/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:21:23 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/04 19:57:51 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	base_valid(char *base, int nbr)
{
	int i;

	i = ft_strlen(base);
	if (i < 2)
		return ;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
}

void	ft_strstr(char *base, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return ;
		}
		i++;
	}
}

void	ft_putnbr_base1(int nbr, char *base, char *arr, int len)
{
	int i;

	i = len - 1;
	while (i >= 0 && nbr > 0)
	{
		arr[i] = base[(nbr % len) * -1];
		nbr /= len;
		i--;
	}
	write(1, "-", 1);
	write(1, arr, len);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		i;
	int		j;
	char	arr[11];

	ft_strstr(base, len);
	base_valid(base, nbr);
	len = ft_strlen(base);
	i = len - 1;
	if (nbr < 0)
		ft_putnbr_base1(nbr, base, arr, len);
	while (i >= 0 && nbr > 0)
	{
		j = nbr % len;
		nbr /= len;
		arr[i] = base[j];
		i--;
	}
	write(1, arr, len);
}
