/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki </var/mail/hyungjki>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 09:57:54 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/27 08:48:57 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	atoi(char *str, int **puzzle);
void	free_arrs(int **arrs, n);
int		**init_puzzle(int *argv):
int     main(int argc, char *argv[])
{
    int len;
		
    len = 0;
    
	if (argc != 3)
	{	write(1, "Error\n", 6);
		return (0);
	}
	init_puzzle(argv[1]);
}
