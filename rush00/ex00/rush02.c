/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:59:03 by suhshin           #+#    #+#             */
/*   Updated: 2020/10/18 14:13:07 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		find_x_fl(int x, int y_flag, int x_size)
{
	if (x == 1)
		return (0 + y_flag);
	else if (x == x_size)
		return (2 + y_flag);
	else
		return (1 + y_flag);
}

int		find_y_flag(int x, int y, int x_size, int y_size)
{
	if (y == 1)
		return (find_x_fl(x, 10, x_size));
	else if (y < y_size)
		return (find_x_fl(x, 20, x_size));
	else
		return (find_x_fl(x, 30, x_size));
}

void	rush(int x_index, int y_index)
{
	int y;
	int x;
	int fl;

	y = 1;
	while (x_index > 0 && y_index > 0 && y <= y_index)
	{
		x = 1;
		while (x <= x_index)
		{
			fl = find_y_flag(x, y, x_index, y_index);
			if (fl == 10 || fl == 12)
				ft_putchar('A');
			else if (fl == 30 || fl == 32)
				ft_putchar('C');
			else if (fl == 21)
				ft_putchar(' ');
			else
				ft_putchar('B');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
