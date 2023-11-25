/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:10:22 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 18:42:16 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_digit_u(unsigned int nb)
{
	if (nb / 10 == 0)
		return (1);
	else
		return (get_digit_u(nb / 10) + 1);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ans;
	size_t	i;
	size_t	len;

	len = get_digit_u(n);
	ans = ft_calloc(len + 1, sizeof(char));
	if (!ans)
		return (NULL);
	i = len;
	while (i > 0)
	{
		ans[i - 1] = '0' + n % 10;
		n /= 10;
		i--;
	}
	return (ans);
}
