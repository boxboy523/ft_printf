/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:31:28 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/14 19:55:47 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	const char		char_c = (char)c;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == char_c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
