/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:07:30 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/14 21:13:09 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	const size_t	max = 4294967295;

	if (size != 0 && max / size < count)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, count * size);
	return (mem);
}
