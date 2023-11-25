/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:34:08 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/14 20:13:23 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	const size_t	len = ft_strlen(s) + 1;
	const char		char_c = (char)c;

	i = 0;
	while (i < len)
	{
		if (s[i] == char_c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
