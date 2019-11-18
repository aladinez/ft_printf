/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:24:07 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/16 16:20:29 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_conv(const char *fmt, va_list args)
{
	int i;

	if (*fmt == 'c')
		ft_putchar(va_arg(args, int));
	else if (*fmt == 's')
		ft_putstr(va_arg(args, char*));
	else if (*fmt == 'p')
	{
		ft_putstr("0x");
		ft_putuhexa(va_arg(args, long long), 0);
	}
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr(va_arg(args, int));
	else if (*fmt == 'u')
		ft_putunbr(va_arg(args, unsigned int));
	else if (*fmt == 'x' || *fmt == 'X')
	{
		i = (*fmt == 'x' ? 0 : 1);
		ft_putuhexa(va_arg(args, long long), i);
	}
	else if (*fmt == '%')
		ft_putchar('%');
}

void	ft_putuhexa(unsigned long long nbr, int j)
{
	char				*str;
	char				c;
	unsigned long long	num;
	unsigned long long	n1;
	unsigned long long	i;

	i = 1;
	str = (j == 1 ? "0123456789ABCDEF" : "0123456789abcdef");
	n1 = nbr;
	while (nbr /= 16)
		i *= 16;
	while (i)
	{
		num = n1 / i;
		num %= 16;
		c = str[num];
		ft_putchar(c);
		i /= 16;
	}
}

void	ft_putunbr(unsigned int n)
{
	int				i;
	unsigned int	num;
	unsigned int	n1;

	i = 1;
	n1 = n;
	while (n1 /= 10)
		i *= 10;
	while (i)
	{
		num = n / i;
		num = (num % 10) + 48;
		ft_putchar(num);
		i /= 10;
	}
}

int		ft_strlen(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	if (c < 0 || c > 127)
		return ;
	write(1, &c, 1);
}
