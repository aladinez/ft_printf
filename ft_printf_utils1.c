/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:58:11 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/20 17:05:04 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	int				i;
	unsigned int	num;
	unsigned int	n1;
	unsigned int	n2;

	i = 1;
	if (n < 0)
	{
		ft_putchar('-');
		n2 = -n;
	}
	else
		n2 = n;
	n1 = n2;
	while (n1 /= 10)
		i *= 10;
	while (i)
	{
		num = n2 / i;
		num = (num % 10) + 48;
		ft_putchar(num);
		i /= 10;
	}
}

int		handling(t_info infos, va_list args)
{
	int		i;
	char	*str;

	i = 0;
	if (infos.conversion == 's')
		i += ft_string(infos, args);
	else if (infos.conversion == '%')
		i += ft_percent(infos);
	else if (infos.conversion == 'c')
		i += ft_char(infos, args);
	else if (infos.conversion == 'd' || infos.conversion == 'i')
	{
		str = ft_decimal(infos, args);
		ft_putstr(str);
		i += ft_strlen(str);
		free(str);
	}
	else if (infos.conversion == 'u')
		i += ft_unsigned(infos, args);
	else if (infos.conversion == 'p')
		i += ft_adress(infos, args);
	else if (infos.conversion == 'x' || infos.conversion == 'X')
		i += ft_hexa(infos, args);
	return (i);
}
