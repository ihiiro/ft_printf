/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:17:07 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/23 20:56:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	yputchar(char chr, int *bytes);
int	yputstr(char *str, int *bytes);
int	yputnbr(long n, char c, int *bytes);

#endif