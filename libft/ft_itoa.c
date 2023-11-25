/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:53:29 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 18:07:32 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digit(unsigned int nb)
{
	if (nb / 10 == 0)
		return (1);
	else
		return (get_digit(nb / 10) + 1);
}

char	*ft_itoa(int n)
{
	unsigned int		num;
	char				*ans;
	unsigned int		i;
	size_t				len;
	const unsigned int	sign = n < 0;

	num = n * ((sign) * -2 + 1);
	len = get_digit(num) + sign;
	ans = ft_calloc(len + 1, sizeof(char));
	if (!ans)
		return (NULL);
	i = len;
	while (i > sign)
	{
		ans[i - 1] = '0' + num % 10;
		num /= 10;
		i--;
	}
	if (sign)
		ans[i - 1] = '-';
	return (ans);
}
