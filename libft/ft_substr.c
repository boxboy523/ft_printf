/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:40:26 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/14 22:25:17 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			substr_size;
	char			*substr;
	unsigned int	i;

	if (len + start > ft_strlen(s))
		substr_size = ft_strlen(s) - start;
	else
		substr_size = len;
	if (start >= ft_strlen(s))
		substr_size = 0;
	substr = ft_calloc(substr_size + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_size)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
