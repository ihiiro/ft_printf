/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:24:10 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/24 12:31:35 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_negx(int n, int *bytes)
{
	if (n <= 0)
	{
		if (!yputnbr_hex((unsigned int)n, n, "0123456789ABCDEF", bytes))
			return (0);
	}
	return (1);
}

int	handle_hex(int n, char spec, int *bytes)
{
	if (spec == 'x' && n >= 0)
	{
		if (!yputnbr_hex(n, n, "0123456789abcdef", bytes))
			return (0);
	}
	else if (spec == 'x' && n <= 0)
	{
		if (!yputnbr_hex((unsigned int)n, n, "0123456789abcdef", bytes))
			return (0);
	}
	else if (!handle_negx(n, bytes))
		return (0);
	else if (spec == 'X' && n > 0)
	{
		if (!yputnbr_hex(n, n, "0123456789ABCDEF", bytes))
			return (0);
	}
	// else if (spec == 'p')
	// {
	// 	if (write(1, "0x", 2) == -1)
	// 		return (0);
	// 	if (!yputnbr_hex(n, n, "0123456789abcdef", bytes))
	// 		return (0);
	// }
	return (1);
}

int	handle_specifier(va_list ap, char spec, int *bytes)
{
	if (spec == 'c')
	{
		if (!yputchar(va_arg(ap, int), bytes))
			return (0);
	}
	else if (spec == 's')
	{
		if (!yputstr(va_arg(ap, char *), bytes))
			return (0);
	}
	else if (spec == 'd' || spec == 'i')
	{
		if (!yputnbr(va_arg(ap, int), 0, bytes))
			return (0);
	}
	else if (spec == 'u')
	{
		if (!yputnbr((unsigned int)va_arg(ap, unsigned int), 0, bytes))
			return (0);
	}
	else if (spec == 'x' || spec == 'X' || spec == 'p')
	{
		if (!handle_hex(va_arg(ap, int), spec, bytes))
			return (0);
	}
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
// 	// ft_printf("%d", ft_printf(" %X ", 0));
// 	ft_printf(" %X ", 0);
// }

// %%%%? ??
// %?(invalid) ??

// 10
// A

// 10 / 16

// 0123456789abcdef

// 11110100
// f4