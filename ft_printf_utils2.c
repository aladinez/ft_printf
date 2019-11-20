/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:25:33 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/20 16:54:38 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_string(t_info infos, va_list args)
{
	char	*str;
	int		len;
	char	*ptr;

	len = ft_strcpy(&str, va_arg(args, char*), 0);
	if (infos.precision == 0)
	{
		free(str);
		str = ft_calloc(1, 1);
	}
	else if (infos.precision > 0 && infos.precision < len)
		str = ft_substr(str, 0, infos.precision);
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

int		ft_strcpy(char **dst, char *src, int a)
{
	int		i;
	char	*ptr;

	ptr = "(null)";
	if (src == NULL)
	{
		i = ft_strcpy(dst, ptr, 0);
		return (i);
	}
	i = ft_strlen(src);
	if (((*dst) = malloc(i * sizeof(char))) == NULL)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		(*dst)[i] = src[i];
		i++;
	}
	(*dst)[i] = 0;
	if (a)
		free(src);
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if ((str = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (ft_calloc(1, 1));
	len += start;
	while (start < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	free(s);
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	j = 0;
	if ((str = (char*)malloc(i * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*ft_space(int len, char c)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = malloc(len * sizeof(char))) == NULL)
		return (NULL);
	while (i < len - 1)
	{
		str[i] = c;
		i++;
	}
	str[i] = 0;
	return (str);
}
