/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:26:46 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/20 16:54:00 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_hexa(t_info infos, va_list args)
{
	char	*str;
	char	*ptr;
	int		len;

	len = infos.conversion == 'x' ? 0 : 1;
	str = ft_put_hexa(va_arg(args, unsigned int), len);
	if (*str == '0' && infos.precision == 0)
	{
		free(str);
		str = ft_calloc(1, 1);
	}
	if (infos.precision > 0 && infos.precision > (len = ft_strlen(str)))
		str = ft_strjoin(ft_space(infos.precision - len + 1, '0'), str);
	if ((len = ft_strlen(str)) < infos.width)
	{
		ptr = ft_space(infos.width - len + 1, ' ');
		if (infos.sign == 0)
			str = ft_strjoin(ptr, str);
		else
			str = ft_strjoin(str, ptr);
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_percent(t_info infos)
{
	char	*str;
	int		len;
	char	*ptr;

	str = ft_calloc(2, 1);
	str[0] = '%';
	if (infos.precision > 0 && infos.point == 0)
	{
		str = ft_strjoin(ft_space(infos.precision, '0'), str);
	}
	if ((len = ft_strlen(str)) < infos.width)
	{
		ptr = ft_space(infos.width - len + 1, ' ');
		if (infos.sign == 0)
			str = ft_strjoin(ptr, str);
		else
			str = ft_strjoin(str, ptr);
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_unsigned(t_info infos, va_list args)
{
	char	*str;
	int		len;

	len = ft_strcpy(&str, ft_itoa((long long)va_arg(args, unsigned int)), 1);
	if (*str == '0' && infos.precision == 0)
	{
		free(str);
		str = ft_calloc(1, 1);
	}
	if (infos.precision > 0 && infos.precision > len)
	{
		str = ft_strjoin(ft_space(infos.precision - len + 1, '0'), str);
	}
	if ((len = ft_strlen(str)) < infos.width)
	{
		if (infos.sign == 0)
			str = ft_strjoin(ft_space(infos.width - len + 1, ' '), str);
		else
			str = ft_strjoin(str, ft_space(infos.width - len + 1, ' '));
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_char(t_info infos, va_list args)
{
	char	*str;
	int		len;
	char	c;

	c = va_arg(args, int);
	if ((len = infos.width) > 1)
	{
		str = ft_space(len, ' ');
		if (infos.sign == 0)
		{
			ft_putstr(str);
			write(1, &c, 1);
		}
		else
		{
			write(1, &c, 1);
			ft_putstr(str);
		}
		free(str);
	}
	else if ((len = 1))
		write(1, &c, 1);
	return (len);
}
