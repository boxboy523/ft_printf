/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:57:47 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 18:38:30 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int num, t_darr *arr)
{
	char	*str;
	int		rtn;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	rtn = print_str(str, arr);
	free(str);
	return (rtn);
}

int	print_uint(unsigned int num, t_darr *arr)
{
	char	*str;
	int		rtn;

	str = ft_uitoa(num);
	if (!str)
		return (-1);
	rtn = print_str(str, arr);
	free(str);
	return (rtn);
}
