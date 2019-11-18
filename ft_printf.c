/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:21:15 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/17 20:14:58 by aez-zaou         ###   ########.fr       */
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
		infos->sign = a > 0 ? 0 : 1;
	}
	infos->width = ft_abs(a);
	
	if ((*fmt == '.') && (*fmt++) && ++i)
	{
		a = 0;
		while ((*fmt >= '0' && *fmt <= '9') && (*fmt++) && ++i)
			a = a * 10 + (*(fmt - 1) - 48);
		if ((*fmt == '*') && (*fmt++) && ++i)
			a = va_arg(args, int);
		infos->precision = a;
	}
	else if (x)
	{
		infos->precision = infos->width - 1;
		infos->width = 0;
	}
	infos->conversion = *fmt;
	return (i);
}

void	initialise(t_info *infos)
{
	infos->sign = 0;
	infos->width = 0;
	infos->precision = -1;
	infos->conversion = 0;
}

char	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (size == 0)
	{
		if ((tab = malloc(1)) == NULL)
			return (NULL);
		ft_bzero(tab, 1);
		return (tab);
	}
	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
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
