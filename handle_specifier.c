/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:52:28 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/25 13:36:42 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertible(char spec)
{
	return (spec == 'c' || spec == 's' || spec == 'd' || spec == 'i'
		|| spec == 'u' || spec == 'x' || spec == 'X' || spec == 'p');
}

int	handle_specifier(va_list ap, char spec, int *bytes)
{
	if (!convertible(spec))
	{
		if (write(1, &spec, 1) == -1)
			return (0);
		*bytes += 1;
		return (1);
	}
	if (spec == 'c')
		if (!yputchar(va_arg(ap, int), bytes))
			return (0);
	if (spec == 's')
		if (!yputstr(va_arg(ap, char *), bytes))
			return (0);
	if (spec == 'd' || spec == 'i')
		if (!yputnbr(va_arg(ap, int), 0, bytes))
			return (0);
	if (spec == 'u')
		if (!yputnbr((unsigned int)va_arg(ap, unsigned int), 0, bytes))
			return (0);
	if (spec == 'x' || spec == 'X' || spec == 'p')
	{
		if (!handle_hex(va_arg(ap, int), spec, bytes)) // --> unsigned long?
			return (0);
	}
	return (1);
}
