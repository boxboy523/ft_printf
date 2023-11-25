/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:38:26 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/09 14:54:41 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	int				cmp1;
	int				cmp2;
	unsigned char	*cs1;
	unsigned char	*cs2;

	index = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (index < n)
	{
		if (cs1[index] != cs2[index])
		{
			cmp1 = cs1[index];
			cmp2 = cs2[index];
			return (cmp1 - cmp2);
		}
		index++;
	}
	return (0);
}
