/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:39:31 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/04 18:20:10 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sign_check(int sign)
{
	if (sign % 2 == 0)
		return (1);
	return (-1);
}

int		ft_atoi(char *str)
{
	int sign;
	int number;

	sign = 0;
	number = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * sign_check(sign));
}
