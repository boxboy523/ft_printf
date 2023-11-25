/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:15:23 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/10 20:42:03 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*dup;
	int			idx;
	const int	size = ft_strlen(src);

	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		dup[idx] = src[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}
