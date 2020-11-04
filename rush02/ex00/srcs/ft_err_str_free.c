/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_str_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:03:03 by jpyo              #+#    #+#             */
/*   Updated: 2020/10/31 22:41:10 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_puterror(void)
{
	write(1, "Error\n", 6);
}

void	ft_dicerror(void)
{
	write(1, "Dict Error\n", 11);
}

void	*ft_free(void *arr)
{
	free(arr);
	return (NULL);
}

void	*ft_free_2d(char **arr, int row)
{
	while (--row)
		arr[row] = ft_free(arr[row]);
	arr = ft_free(arr);
	return (NULL);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
