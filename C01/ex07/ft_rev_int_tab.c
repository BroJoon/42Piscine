/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:36:22 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/18 11:56:30 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = size - 1;
	j = 0;
	while (size / 2 > j)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		i--;
		j++;
	}
}
