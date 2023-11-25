/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:42:36 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/11 20:03:19 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;
	size_t	i;
	size_t	range;

	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_size = ft_strlen(needle);
	i = 0;
	range = len - needle_size + 1;
	if (range > len)
		range = 0;
	while (haystack[i] && i < range)
	{
		if (ft_strncmp(haystack + i, needle, needle_size) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
