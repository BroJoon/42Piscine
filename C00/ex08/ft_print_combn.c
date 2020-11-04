/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:31:19 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/28 11:13:51 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_string(int n, int *buf)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = buf[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (!(buf[0] == 10 - n && buf[n - 1] == 9))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	dfs(int depth, int n, int *buf)
{
	int i;

	if (depth == n)
	{
		put_string(n, buf);
		return ;
	}
	if (depth == 0)
		i = 0;
	else
		i = buf[depth - 1] + 1;
	while (i < 10)
	{
		buf[depth] = i;
		dfs(depth + 1, n, buf);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int buf[10];

	dfs(0, n, buf);
}
