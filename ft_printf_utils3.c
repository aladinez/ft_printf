/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:01:19 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/17 20:20:08 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		handle_decimal(t_info infos, va_list args)
{
	char	*str;
	char	*ptr;
	int		len;

	len = ft_strcpy(&str, ft_itoa(va_arg(args, int)));
	if (*str == '0' && infos.precision == 0)
		str[0] = '\0';
	if (infos.precision > 0 && infos.precision > len)
	{
		if (*str == '-')
		{
			ptr = ft_calloc(2, 1);
			ptr[0] = '-';
			str = ft_substr(str, 1, ft_strlen(str) - 1);
			str = ft_strjoin(ft_space(infos.precision - len + 2, '0'), str);
			str = ft_strjoin(ptr, str);
		}
		else
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

void	fill(char *str, int dim, int n)
{
	unsigned int n2;

	n2 = 0;
	if (n < 0)
	{
		str[0] = '-';
		n2 = -n;
	}
	else
		n2 = n;
	while (n2)
	{
		str[dim -= 1] = (n2 % 10) + 48;
		n2 /= 10;
	}
}

char	*zero(void)
{
	char	*str;

	if ((str = (char*)malloc(2 * sizeof(char))) == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int		count(int dim, unsigned int n1)
{
	while (n1 /= 10)
		dim++;
	return (dim);
}

char	*ft_itoa(int n)
{
	unsigned int	n1;
	int				dim;
	char			*str;

	if (n == 0)
	{
		str = zero();
		return (str);
	}
	else if (n < 0)
	{
		dim = 2;
		n1 = -n;
	}
	else
	{
		dim = 1;
		n1 = n;
	}
	dim = count(dim, n1);
	if ((str = (char*)malloc((dim + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[dim] = '\0';
	fill(str, dim, n);
	return (str);
}
