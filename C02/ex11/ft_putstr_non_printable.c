/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:06:28 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/04 16:13:50 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*arr;
	unsigned char	c;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	arr = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			c = str[i];
			a = c / 16;
			b = c % 16;
			write(1, "\\", 1);
			write(1, &arr[a], 1);
			write(1, &arr[b], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
