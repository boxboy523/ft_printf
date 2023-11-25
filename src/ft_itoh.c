/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:21:11 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 20:31:55 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_get_digit(unsigned long long nb)
{
	if (nb / 16 == 0)
		return (1);
	else
		return (hex_get_digit(nb / 16) + 1);
}

char	*ft_itoh(unsigned int n, int upper)
{
	char	*ans;
	size_t	len;
	size_t	i;

	len = hex_get_digit(n);
	ans = ft_calloc(len + 1, sizeof(char));
	if (!ans)
		return (NULL);
	i = len;
	while (i > 0)
	{
		ans[i - 1] = '0' * (n % 16 <= 9) + ('a' - 10) * (n % 16 > 9) \
		* !upper + ('A' - 10) * (n % 16 > 9) * upper + n % 16;
		n /= 16;
		i--;
	}
	return (ans);
}

char	*ft_lltoh(unsigned long long n, int upper)
{
	char	*ans;
	size_t	len;
	size_t	i;

	len = hex_get_digit(n);
	ans = ft_calloc(len + 1, sizeof(char));
	if (!ans)
		return (NULL);
	i = len;
	while (i > 0)
	{
		ans[i - 1] = '0' * (n % 16 <= 9) + ('a' - 10) * (n % 16 > 9) \
		* !upper + ('A' - 10) * (n % 16 > 9) * upper + n % 16;
		n /= 16;
		i--;
	}
	return (ans);
}
