/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:24:10 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/25 13:36:12 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		bytes;

	va_start(ap, str);
	bytes = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '\0')
				break ;
			if (*(str + 1) == '%') // --> handle_specifier.c
			{
				if (write(1, "%", 1) == -1)
					return (-1);
				bytes++;
			}
			else
				if (!handle_specifier(ap, *(str + 1), &bytes))
					return (-1);
			str += 2;
			continue ;
		}
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		bytes++;
	}
	va_end(ap);
	return (bytes);
}

// int	main(void)
// {
// 	printf("%d", printf(" % "));
// }

// %%%%? ??
// %?(invalid) ??

// 10
// A

// 10 / 16

// 0123456789abcdef

// 11110100
// f4