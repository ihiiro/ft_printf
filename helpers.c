/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:57:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/23 18:49:53 by yel-yaqi         ###   ########.fr       */
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
			return (-1);
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
