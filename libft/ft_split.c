/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:39:33 by junyekim          #+#    #+#             */
/*   Updated: 2023/10/15 19:51:55 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_set_len(const char *str, char c, size_t str_len)
{
	unsigned int		iter;
	unsigned int		set_len;

	iter = 0;
	set_len = 0;
	while (iter < str_len)
	{
		if ((iter == 0 || str[iter - 1] == c) && str[iter] != c)
			set_len++;
		iter++;
	}
	return (set_len);
}

static char	**check_ans(char **ans, size_t size)
{
	unsigned int	i;

	if (!ans)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!ans[i])
		{
			i = 0;
			while (i < size)
			{
				if (ans[i])
					free(ans[i]);
				i++;
			}
			free(ans);
			return (NULL);
		}
		i++;
	}
	return (ans);
}

static char	**find_set(const char *str, char c, size_t size)
{
	unsigned int		iter;
	unsigned int		start;
	unsigned int		ans_idx;
	char				**ans;
	const size_t		set_len = get_set_len(str, c, size);

	ans = ft_calloc(set_len + 1, sizeof(char *));
	if (!ans)
		return (NULL);
	iter = 0;
	ans_idx = 0;
	while (iter < size)
	{
		if ((iter == 0 || str[iter - 1] == c) && str[iter] != c)
			start = iter;
		if ((iter == size - 1 || str[iter + 1] == c) && str[iter] != c)
			ans[ans_idx++] = ft_substr(str, start, iter - start + 1);
		iter++;
	}
	return (check_ans(ans, set_len));
}

char	**ft_split(const char *s, char c)
{
	char			**ans;
	const size_t	str_len = ft_strlen(s);

	ans = find_set(s, c, str_len);
	return (ans);
}
