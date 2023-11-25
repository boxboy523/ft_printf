/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:41:26 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/14 19:54:27 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	const size_t	len = ft_strlen(s) + 1;
	const char		char_c = (char)c;

	i = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == char_c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
