/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:57:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/25 19:29:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	yputchar(char chr, int *bytes)
{
	if (write(1, &chr, 1) == -1)
		return (-1);
	*bytes += 1;
	return (1);
}

int	yputstr(char *str, int *bytes)
{
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*bytes += 6;
		return (1);
	}
	while (*str)
	{
		if (write(1, str, 1) == -1)
			return (-1);
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
				return (-1);
			*bytes += 1;
		}
		if (write(1, &c, 1) == -1)
			return (-1);
		*bytes += 1;
		return (1);
	}
	yputnbr(n / 10, c, bytes);
	if (write(1, &c, 1) == -1)
		return (-1);
	*bytes += 1;
	return (1);
}

int	yputnbr_hex(long dec, long original, char *hex, int *bytes)
{
	if (dec == 0)
	{
		if (original == dec)
		{
			if (write(1, "0", 1) == -1)
				return (-1);
			*bytes += 1;
		}
		return (1);
	}
	if (dec >= 16)
	{
		yputnbr_hex(dec / 16, original, hex, bytes);
		if (write(1, &hex[dec % 16], 1) == -1)
			return (-1);
		*bytes += 1;
	}
	else
	{
		if (write(1, &hex[dec], 1) == -1)
			return (-1);
		*bytes += 1;
		yputnbr_hex(dec / 16, original, hex, bytes);
	}
	return (1);
}

int	yputad(unsigned long dec, unsigned long original, char *hex, int *bytes)
{
	if (dec == 0)
	{
		if (original == dec)
		{
			if (write(1, "0", 1) == -1)
				return (-1);
			*bytes += 1;
		}
		return (1);
	}
	if (dec >= 16)
	{
		yputnbr_hex(dec / 16, original, hex, bytes);
		if (write(1, hex + (dec % 16), 1) == -1)
			return (-1);
		*bytes += 1;
	}
	else
	{
		if (write(1, hex + dec, 1) == -1)
			return (-1);
		*bytes += 1;
		yputnbr_hex(dec / 16, original, hex, bytes);
	}
	return (1);
}
