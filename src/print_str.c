/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:49:18 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 21:33:33 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str, t_darr *arr)
{
	int	rtn;

	if (!str)
	{
		rtn = darr_append_arr(arr, "(null)", 6);
		return (6);
	}
	if (darr_append_arr(arr, str, ft_strlen(str)) == -1)
		return (-1);
	return (ft_strlen(str));
}
