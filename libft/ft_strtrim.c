/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:22:36 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/11 18:24:02 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*rtn;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	rtn = ft_calloc(end - start + 1, sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		rtn[i] = s1[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
