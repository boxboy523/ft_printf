/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:43:01 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/14 20:46:20 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	const size_t	len = ft_strlen(s);
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		f(i, &(s[i]));
		i++;
	}
}
