/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:22:24 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/21 13:03:12 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char first;
	char second;
	char third;

	first = '0';
	while (first < '7')
	{
		second = first + 1;
		while (second < '9')
		{
			third = second + 1;
			while (third <= '9')
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				write(1, ", ", 2);
				third++;
			}
			second++;
		}
		first++;
	}
	write(1, "789", 3);
}
