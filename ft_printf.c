/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:41:54 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/20 17:43:10 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_printf(const char *fmt, ...)
{
	int		i;
	t_info	infos;
	va_list	args;

	va_start(args, fmt);
	i = 0;
	while (*fmt != 0)
	{
		initialise(&infos);
		if (*fmt == '%')
		{
			fmt++;
			fmt += get_info(fmt, &infos, args);
			i += handling(infos, args);
		}
		else
		{
			ft_putchar(*fmt);
			i++;
		}
		fmt++;
	}
	return (i);
}

int		get_info(const char *fmt, t_info *infos, va_list args)
{
	int a;
	int i;
	int x;

	i = 0;
	a = 0;
	while (*fmt == '-' && (*fmt++) && ++i)
		infos->sign = 1;
	x = (*fmt == '0') ? 1 : 0;
	while ((*fmt >= '0' && *fmt <= '9') && (*fmt++) && ++i)
		a = a * 10 + (*(fmt - 1) - 48);
	if ((*fmt == '*') && (*fmt++) && ++i)
	{
		a = va_arg(args, int);
		if (a < 0 && infos->sign == 0)
			infos->sign = 1;
	}
	infos->width = a > 0 ? a : -a;
	if ((*fmt == '.') && (*fmt++) && ++i)
	{
		a = 0;
		while ((*fmt >= '0' && *fmt <= '9') && (*fmt++) && ++i)
			a = a * 10 + (*(fmt - 1) - 48);
		if ((*fmt == '*') && (*fmt++) && ++i)
			a = va_arg(args, int);
		infos->precision = a;
	}
	else if (x && a != 0)
		split_getinfo(&infos, a);
	else
		infos->point = 2;
	infos->conversion = *fmt;
	return (i);
}

void	split_getinfo(t_info **infos, int a)
{
	(*infos)->point = 0;
	(*infos)->precision = (*infos)->width;
	(*infos)->width = 0;
	if (a < 0)
	{
		(*infos)->width = (*infos)->precision;
		(*infos)->precision = -1;
	}
}

void	initialise(t_info *infos)
{
	infos->sign = 0;
	infos->width = 0;
	infos->precision = -1;
	infos->conversion = 0;
	infos->point = -1;
}

void	ft_bzero(void *s, size_t n)
{
	size_t			j;
	unsigned char	*str;

	str = (unsigned char*)s;
	j = 0;
	while (j < n)
	{
		str[j] = 0;
		j++;
	}
}
