/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki </var/mail/hyungjki>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:55:33 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/27 08:49:19 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int strlen (char *str)
{
	int i;

	i = 0;
	while (str != '\0')
	{
		i++
	}
	return (i);_
}


void	atoi(char *str, int **puzzle)
{
	int i;
	int j;

	i = 0;
	j = 0;
   	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			init[j] = str[i] - '0';
			i++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				init[j] = init[j] * 10 + str[i] - '0';
			}	
		}
		i++;
	}
}

int		**malloc_arrs(int n)
{
	int i;
	int		**arr;

	i = 0;
	arr = (int **)malloc(sizeof(int *) * n);
	while (i < n)
	{
		arr[i++] = (int *)malloc(sizeof(int) * n);
	}
	return (arr);

}

void	free_arrs(int **arrs, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(arrs[i]);
		i++;
	}
	free(arrs);
}
