/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:13:56 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/11 20:22:19 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	char			*rtn;
	const size_t	s1_size = ft_strlen(s1);
	unsigned int	i;

	rtn = ft_calloc(len, sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		rtn[s1_size + i] = s2[i];
		i++;
	}
	rtn[s1_size + i] = '\0';
	return (rtn);
}
