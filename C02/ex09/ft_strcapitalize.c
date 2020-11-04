/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:43:39 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/25 04:11:30 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_first(char *str, int index)
{
	if (index == 0)
		return (1);
	if (str[index - 1] <= '9' && str[index - 1] >= '0')
		return (0);
	if (str[index - 1] <= 'Z' && str[index - 1] >= 'A')
		return (0);
	if (str[index - 1] <= 'z' && str[index - 1] >= 'a')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (find_first(str, i))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= c;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += c;
		}
		i++;
	}
	return (str);
}
