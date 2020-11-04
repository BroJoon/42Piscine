/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_seperate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <vywnstlr@naver.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:19:01 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 18:19:01 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"
#include <stdlib.h>

int		input_dash(char **str, int row)
{
	if ((str[row] = (char *)malloc(sizeof(char) * 2)) == NULL)
	{
		str = ft_free_2d(str, row);
		return (-1);
	}
	str[row][0] = '-';
	str[row][1] = '\0';
	return (row + 1);
}
