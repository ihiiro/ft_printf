/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:52:58 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/25 12:14:42 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	handle_negx(int n, int *bytes)
// {
// 	if (n <= 0)
// 	{
// 		if (!yputnbr_hex((unsigned int)n, n, "0123456789ABCDEF", bytes))
// 			return (0);
// 	}
// 	return (1);
// }

int	handle_hex(int n, char spec, int *bytes)
{
	if (spec == 'x' && n >= 0)
		if (!yputnbr_hex(n, n, "0123456789abcdef", bytes))
			return (0);
	if (spec == 'x' && n < 0)
		if (!yputnbr_hex((unsigned int)n, n, "0123456789abcdef", bytes))
			return (0);
	if (spec == 'X' && n >= 0)
		if (!yputnbr_hex(n, n, "0123456789ABCDEF", bytes))
			return (0);
	if (spec == 'X' && n < 0)
	{
		if (!yputnbr_hex((unsigned int)n, n, "0123456789ABCDEF", bytes))
			return (0);
	}
	// if (spec == 'p')
	// {
	// 	if (write(1, "0x", 2) == -1)
	// 		return (0);
	// 	if (!yputnbr_hex(n, n, "0123456789abcdef", bytes))
	// 		return (0);
	// }
	return (1);
}
