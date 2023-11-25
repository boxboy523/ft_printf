/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:10:07 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 21:12:25 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARR_H
# define DARR_H
# include <stdlib.h>
# include "libft.h"

typedef struct s_darr
{
	char	*data;
	size_t	size;
	size_t	len;
}	t_darr;
t_darr	darr_init(size_t size);
int		darr_setidx(t_darr arr, size_t index, char value);
int		darr_append(t_darr *arr, char value);
char	darr_pop(t_darr *arr);
int		darr_append_arr(t_darr *arr, const char *ls, size_t len);
int		darr_free(t_darr *arr);
#endif