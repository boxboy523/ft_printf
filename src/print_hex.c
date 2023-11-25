/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:24:05 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 21:36:36 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hexdump(void *hex)
{
	char	*rtn;
	char	*hexascii;
	size_t	size;
	size_t	i;

	hexascii = ft_lltoh((unsigned long long) hex, 0);
	if (!hexascii)
		return (NULL);
	size = ft_strlen(hexascii);
	rtn = ft_calloc(size + 3, sizeof(char));
	if (!rtn)
	{
		free(hexascii);
		return (NULL);
	}
	ft_strlcat(rtn, "0x", 3);
	i = 3;
	ft_strlcat(rtn, hexascii, size + 3);
	free(hexascii);
	return (rtn);
}

int	print_hex(unsigned int num, int upper, t_darr *arr)
{
	char	*str;
	int		rtn;

	str = ft_itoh(num, upper);
	if (!str)
		return (-1);
	rtn = print_str(str, arr);
	free(str);
	return (rtn);
}

int	print_ptr(void *p, t_darr *arr)
{
	char	*str;
	int		rtn;

	str = hexdump(p);
	if (!str)
		return (-1);
	rtn = print_str(str, arr);
	free(str);
	return (rtn);
}
/*
#include <stdio.h>
int main(void)
{
	void	*p;
	char	c;

	c = 1;
	p = &c;
	printf("%s, %p\n", hexdump(p), p);
}*/