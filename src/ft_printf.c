/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:11:56 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 21:39:09 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_darr	arr;
	int		rtn;

	va_start(ap, fmt);
	arr = darr_init(10);
	if (arr.size == 0)
		return (-1);
	if (fmt_print(fmt, ap, &arr) == -1)
	{
		free(arr.data);
		return (-1);
	}
	va_end(ap);
	rtn = write(1, arr.data, arr.len);
	free(arr.data);
	return (rtn);
}

int	fmt_print(const char *fmt, va_list ap, t_darr *arr)
{
	size_t	i;
	int		out;

	i = 0;
	while (fmt[i])
	{
		out = 1;
		if (fmt[i] == '%')
			out = fmt_flag(fmt[++i], ap, arr);
		else
			out = darr_append(arr, fmt[i]);
		if (out == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	fmt_flag(char f, va_list ap, t_darr *arr)
{
	int	rtn;

	if (f == 'd')
		rtn = print_int(va_arg(ap, int), arr);
	if (f == 'c')
		rtn = darr_append(arr, (char)va_arg(ap, int)) * 2 + 1;
	if (f == 's')
		rtn = print_str(va_arg(ap, char *), arr);
	if (f == 'p')
		rtn = print_ptr(va_arg(ap, void *), arr);
	if (f == 'i')
		rtn = print_int(va_arg(ap, int), arr);
	if (f == 'u')
		rtn = print_uint(va_arg(ap, unsigned int), arr);
	if (f == 'x')
		rtn = print_hex(va_arg(ap, unsigned int), 0, arr);
	if (f == 'X')
		rtn = print_hex(va_arg(ap, unsigned int), 1, arr);
	if (f == '%')
		rtn = darr_append(arr, '%') * 2 + 1;
	return (rtn);
}

/*
#include <stdio.h>

int	main(void)
{
	int	i;

	ft_printf(" %p ", -1);
	printf(" %p ", -1);
	return (0);
}
*/