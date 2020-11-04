/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:53:01 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/21 16:08:34 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	make_pattern(char *number, int first, int last)
{
	number[0] = first / 10 + '0';
	number[1] = first % 10 + '0';
	number[3] = last / 10 + '0';
	number[4] = last % 10 + '0';
	if (first == 98 && last == 99)
	{
		write(1, number, 5);
	}
	else
	{
		write(1, number, 7);
	}
}

void	ft_print_comb2(void)
{
	int		first;
	int		last;
	char	number[7];

	first = 0;
	number[2] = ' ';
	number[5] = ',';
	number[6] = ' ';
	while (first <= 98)
	{
		last = first + 1;
		while (last <= 99)
		{
			make_pattern(number, first, last);
			last++;
		}
		first++;
	}
}
