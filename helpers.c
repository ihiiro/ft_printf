/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:57:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/23 21:02:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	yputchar(char chr, int *bytes)
{
	if (write(1, &chr, 1) == -1)
		return (0);
	*bytes += 1;
	return (1);
}

int	yputstr(char *str, int *bytes)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (0);
		*bytes += 6;
		return (1);
	}
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (0);
		*bytes += 1;
		str++;
	}
	return (1);
}

int	yputnbr(long n, char c, int *bytes)
{
	c = -n % 10 + '0';
	if (!(c >= 48 && c <= 57))
		c = n % 10 + '0';
	if ((-n + '0' >= 48 && - n + '0' <= 57) || (n + '0' >= 48 && n + '0' <= 57))
	{
		if (n < 0)
		{
			if (write(1, "-", 1) == -1)
				return (0);
			*bytes += 1;
		}
		if (write(1, &c, 1) == -1)
			return (0);
		*bytes += 1;
		return (1);
	}
	yputnbr(n / 10, c, bytes);
	if (write(1, &c, 1) == -1)
		return (0);
	*bytes += 1;
	return (1);
}
