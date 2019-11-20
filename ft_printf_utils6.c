/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:55:15 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/11/20 16:46:15 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_precision(t_info infos, char **str, int len)
{
	char *ptr;

	ptr = ft_calloc(2, 1);
	ptr[0] = '-';
	*str = ft_substr(*str, 1, ft_strlen(*str) - 1);
	if (infos.point == 0)
		len++;
	*str = ft_strjoin(ft_space(infos.precision - len + 2, '0'), *str);
	*str = ft_strjoin(ptr, *str);
}
