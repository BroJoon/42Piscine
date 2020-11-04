/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_puzzle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki </var/mail/hyungjki>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:55:59 by hyungjki          #+#    #+#             */
/*   Updated: 2020/10/27 08:51:04 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strlen(cahr *src);
int ** malloc(int **puzzle);
void atoi(char *src, int **puzzle);

int    **init_puzzle(int *argv)
{
	int len;

	len = 0;
	len = strlen(argv);
	if ( len % 2 != 0)
	{
		write(1, 'Error\n', 6);
		return (0);
	}
	int **puzzle = malloc_arrs(len);
	atoi(argv[1], puzzle);
}

void	search_col(int **puzzle, int n)
{

}

void	search_row(int **puzzle, int n)
{
	
}`
