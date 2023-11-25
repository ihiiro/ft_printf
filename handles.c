/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:52:28 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/25 19:43:14 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertible(char spec)
{
	return (spec == 'c' || spec == 's' || spec == 'd' || spec == 'i'
		|| spec == 'u' || spec == 'x' || spec == 'X' || spec == 'p');
}

int	handle_hex(int n, char spec, int *bytes)
{
	if (spec == 'x' && n >= 0)
		if (!yputnbr_hex(n, n, "0123456789abcdef", bytes))
			return (-1);
	if (spec == 'x' && n < 0)
		if (!yputnbr_hex((unsigned int)n, n, "0123456789abcdef", bytes))
			return (-1);
	if (spec == 'X' && n >= 0)
		if (!yputnbr_hex(n, n, "0123456789ABCDEF", bytes))
			return (-1);
	if (spec == 'X' && n < 0)
	{
		if (!yputnbr_hex((unsigned int)n, n, "0123456789ABCDEF", bytes))
			return (-1);
	}
	return (1);
}

int	handle_ad(unsigned long n, int *bytes)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	*bytes += 2;
	if (yputad(n, n, "0123456789abcdef", bytes) == -1)
		return (-1);
	return (1);
}

int	handle_specifier(va_list ap, char spec, int *bytes)
{
	if (!convertible(spec))
	{
		if (write(1, &spec, 1) == -1)
			return (-1);
		*bytes += 1;
	}
	if (spec == 'c')
		if (yputchar(va_arg(ap, int), bytes) == -1)
			return (-1);
	if (spec == 's')
		if (yputstr(va_arg(ap, char *), bytes) == -1)
			return (-1);
	if (spec == 'd' || spec == 'i')
		if (yputnbr(va_arg(ap, int), 0, bytes) == -1)
			return (-1);
	if (spec == 'u')
		if (yputnbr((unsigned int)va_arg(ap, unsigned int), 0, bytes) == -1)
			return (-1);
	if (spec == 'x' || spec == 'X')
		if (handle_hex(va_arg(ap, int), spec, bytes) == -1)
			return (-1);
	if (spec == 'p')
		if (handle_ad(va_arg(ap, unsigned long), bytes) == -1)
			return (-1);
	return (1);
}
