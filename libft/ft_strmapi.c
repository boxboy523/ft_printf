/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:33:13 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/14 20:42:33 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	len = ft_strlen(s);
	char			*rtn;
	unsigned int	i;

	rtn = ft_calloc(len + 1, sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
