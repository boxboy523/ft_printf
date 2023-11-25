/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:57:30 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 21:31:54 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darr.h"

/*
Create darr has size of list. if allocation failed,
size become 0 (it means this arr is wrong arr)
*/
t_darr	darr_init(size_t size)
{
	t_darr	arr;

	if (size == 0)
	{
		arr.data = (void *)0;
		return (arr);
	}
	arr.data = ft_calloc(size, sizeof(char));
	if (!arr.data)
		arr.size = 0;
	else
		arr.size = size;
	arr.len = 0;
	return (arr);
}

/*
Set value where arr[idx]. if idx is wrong, return -1
*/
int	darr_setidx(t_darr arr, size_t index, char value)
{
	if (arr.len <= index)
		return (-1);
	arr.data[index] = value;
	return (0);
}

/*
append new character to darr.
if the size is not enough, resize it.  
it return 0 when it work completely.
if something wrong, return -1
*/
int	darr_append(t_darr *arr, char value)
{
	char	*buf;

	if (arr->size == 0)
		return (-1);
	if (arr->len < arr->size)
	{
		arr->data[arr->len] = value;
		arr->len++;
		return (0);
	}
	buf = ft_calloc(arr->size * 2, sizeof(char));
	if (!buf)
		return (-1);
	ft_memcpy(buf, arr->data, arr->len);
	free(arr->data);
	arr->data = buf;
	arr->size *= 2;
	return (darr_append(arr, value));
}

/*
delete last charecter from arr and return that value. and resize the arr
it return 0 when it work completely.
if something wrong, return -1
*/
char	darr_pop(t_darr *arr)
{
	size_t	i;
	char	*buf;

	if (arr->size == 0 || arr->len == 0)
		return (-1);
	if (arr->len > arr->size / 2)
	{
		arr->len--;
		return (arr->data[arr->len]);
	}
	buf = ft_calloc(arr->size / 2, sizeof(char));
	if (!buf)
		return (-1);
	i = 0;
	while (i < arr->len)
	{
		buf[i] = arr->data[i];
		i++;
	}
	free(arr->data);
	arr->data = buf;
	arr->size /= 2;
	return (darr_pop(arr));
}

/*
append new array to darr.
if the size is not enough, resize it.
it return 0 when it work completely.
if something wrong, return -1
*/
int	darr_append_arr(t_darr *arr, const char *ls, size_t len)
{
	char	*buf;

	if (arr->size == 0)
		return (-1);
	if (arr->len + len < arr->size)
	{
		ft_memcpy(arr->data + arr->len, ls, len);
		arr->len += len;
		return (0);
	}
	buf = ft_calloc(arr->size * 2, sizeof(char));
	if (!buf)
		return (-1);
	ft_memcpy(buf, arr->data, arr->len);
	free(arr->data);
	arr->data = buf;
	arr->size *= 2;
	return (darr_append_arr(arr, ls, len));
}
