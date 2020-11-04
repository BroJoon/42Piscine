/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:02:48 by hyungjki          #+#    #+#             */
/*   Updated: 2020/11/04 16:11:06 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_prime(int nb)
{
	long long	mod;

	mod = 2;
	while (nb >= mod * mod)
	{
		if (nb % mod == 0)
			return (0);
		mod++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (nb % 2 == 0)
		{
			nb++;
			continue;
		}
		if (check_prime(nb))
			return (nb);
		nb++;
	}

 17     mod = 2;
 18     while (nb >= mod * mod)
 19     {}
