/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:36:12 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/21 12:17:40 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(int a)
{
	int length;

	length = 0;
	while (a > 0)
	{
		a = a / 10;
		length++;
	}
	return (length);
}

void	print_string(int length, int nb)
{
	int			i;
	char		arr[11];

	i = length - 1;
	while (i >= 0)
	{
		arr[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	write(1, arr, length);
}

void	ft_putnbr(int nb)
{
	int length;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	length = len(nb);
	print_string(length, nb);
}
