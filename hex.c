/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:52:58 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/25 19:29:23 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
