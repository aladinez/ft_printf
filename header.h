/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:25:23 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/16 16:57:55 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct
{
	int sign;
	int width;
	int precision;
	char conversion;
}t_info;

int		ft_printf(const char *fmt, ...);
void	handle_conv(const char *fmt, va_list args);
void	ft_putuhexa(unsigned long long nbr, int j);
void	ft_putunbr(unsigned int n);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		get_info(const char *fmt, t_info *infos, va_list args);
void	initialise(t_info *infos);
int		ft_strcpy(char **dst, char *src);
int		handle_string(t_info infos, va_list args);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_space(int len, char c);
int		handling(t_info infos, va_list args);
char	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *tab);
int		handle_decimal(t_info infos, va_list args);
char	*ft_itoa(int n);
int		count(int dim, unsigned int n1);
char	*zero(void);
void	fill(char *str, int dim, int n);
int		ft_abs(int a);

#endif

