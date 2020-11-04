/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:06:55 by jpyo              #+#    #+#             */
/*   Updated: 2020/11/01 07:05:47 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

char	*g_fn;

void	ft_puterror(void);
void	ft_dicerror(void);
void	*ft_free(void *arr);
void	*ft_free_2d(char **arr, int row);
int		ft_strlen(char *str);

char	*ft_ignore_zero(char *find);

int		ft_start(char *find, char *fn);
int		ft_search(int fd, char *find, char **str, int row);
int		select_search(char *find, char **str, int row);

int		deep_first_search(char *find, char **str, int row);
int		div_search_start(char *find, char **str, int row);

int		ft_deep_search_0(char *find, char **str, int row);
int		ft_deep_search_0_1(char *find, char **str, int row);
int		ft_deep_search_1(char *arr, char *find, char **str, int row);
int		ft_deep_search_2(char *arr, char *find, char **str, int row);
int		ft_deep_search_3(char *find, char **str, int row);

int		ft_end(char **str, int row);

int		ft_current_buf(char *find, char **str, int len);

int		ft_save_str(int fd, char **str, int row, int buf);

int		input_dash(char **str, int row);

#endif
