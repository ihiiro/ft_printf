/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:24:10 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/23 18:52:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(va_list ap, char spec, int *bytes)
{
	if (spec == 'c')
	{
		if (!yputchar(va_arg(ap, int), bytes))
			return (0);
	}
	else if (spec == 's')
	{
		if (!yputstr(va_arg(ap, char*), bytes))
			return (0);
	}
	// else if (spec == 'd' || spec == 'i')
	// {
	// 	// 
	// }
	return (1);
}

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
			if (*(str + 1) == '%')
			{
				if (write(1, "%", 1) == -1)
					return (-1);
				bytes++;
			}
			else
			{
				if (!handle_specifier(ap, *(str + 1), &bytes))
					return (-1);
			}
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
// 	// ft_printf("f%d", 11);
// 	// int bytes = 0;
// 	char	c = 0;
// 	yputnbr(22, c);
// }

// %%%%? ??
// %?(invalid) ??