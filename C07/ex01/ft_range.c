/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:52:45 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/28 11:30:50 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *range;
	int i;

	i = 0;
	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
