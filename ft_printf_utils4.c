/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:54:14 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/20 17:43:33 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_adress(t_info infos, va_list args)
{
	char	*str;
	char	*ptr;
	int		len;

	str = ft_put_adress(va_arg(args, void*), infos.point);
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

char	*ft_put_adress(void *n, int i)
{
	char			*str;
	char			*ptr;
	unsigned long	num;

	if ((ptr = (char*)malloc(3 * sizeof(char))) == NULL)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = 'x';
	ptr[2] = '\0';
	if (n == NULL && !(i == 0 || i == 2))
		return (ptr);
	else
	{
		num = (unsigned long)n;
		str = ft_strjoin(ptr, ft_put_hexa(num, 0));
		return (str);
	}
}

char	*ft_put_hexa(unsigned long nbr, int a)
{
	char			*str;
	char			*ptr;
	unsigned long	num;
	unsigned long	n1;
	unsigned long	i;

	ptr = ft_calloc(1, 1);
	i = 1;
	str = a == 0 ? "0123456789abcdef" : "0123456789ABCDEF";
	n1 = nbr;
	while (nbr /= 16)
		i *= 16;
	while (i)
	{
		num = n1 / i;
		num %= 16;
		ptr = ft_charjoin(ptr, str[num]);
		i /= 16;
	}
	return (ptr);
}

char	*ft_charjoin(char *str, char c)
{
	char	*ptr;
	int		i;

	i = 0;
	if ((ptr = (char*)malloc((ft_strlen(str) + 2) * sizeof(char))) == NULL)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i++] = c;
	ptr[i] = 0;
	free(str);
	return (ptr);
}
