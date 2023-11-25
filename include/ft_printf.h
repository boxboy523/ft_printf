/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:18:37 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/25 21:01:07 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# include "darr.h"

int		ft_printf(const char *str, ...);
int		fmt_flag(char f, va_list ap, t_darr *arr);
int		fmt_print(const char *fmt, va_list ap, t_darr *arr);
char	*ft_itoh(unsigned int n, int upper);
char	*hexdump(void *hex);
int		print_str(const char *str, t_darr *arr);
int		print_int(int num, t_darr *arr);
int		print_uint(unsigned int num, t_darr *arr);
int		print_hex(unsigned int num, int upper, t_darr *arr);
int		print_ptr(void *p, t_darr *arr);
char	*ft_uitoa(unsigned int n);
char	*ft_itoh(unsigned int n, int upper);
char	*ft_lltoh(unsigned long long n, int upper);
#endif