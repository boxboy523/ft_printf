/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:17:09 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/09 14:55:47 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	const unsigned char	uc_val = (unsigned char) value;
	void				*ptr_origin;

	ptr_origin = ptr;
	while (num > 0)
	{
		*(unsigned char *)ptr = uc_val;
		ptr = (char *)ptr + 1;
		num--;
	}
	return (ptr_origin);
}
