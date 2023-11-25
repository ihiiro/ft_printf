/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:24:10 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/25 19:38:43 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	traverse(va_list ap, const char *str, int *bytes)
{
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '\0')
				break ;
			if (*(str + 1) == '%')
			{
				if (write(1, "%", 1) == -1)
					return (-1);
				*bytes += 1;
			}
			else
				if (handle_specifier(ap, *(str + 1), bytes) == -1)
					return (-1);
			str += 2;
			continue ;
		}
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		*bytes += 1;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		bytes;

	va_start(ap, str);
	if (write(1, "", 0) == -1)
		return (-1);
	bytes = 0;
	if (traverse(ap, str, &bytes) == -1)
		return (-1);
	va_end(ap);
	return (bytes);
}
