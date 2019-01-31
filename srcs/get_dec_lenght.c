/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_lenght.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:10:50 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:35:52 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	get_dec_length_handler(t_ftprintf *t, t_length length)
{
	static t_handler_len	(handler[4]) = {
		{.value = HH, .handle = get_dec_hh_length},
		{.value = H, .handle = get_dec_h_length},
		{.value = L, .handle = get_dec_l_length},
		{.value = LL, .handle = get_dec_ll_length},
	};
	int						i;

	i = -1;
	while (++i < 4)
	{
		if (length == handler[i].value)
		{
			t->i++;
			return ((*handler[i].handle)(t));
		}
	}
	return (0);
}

long long int	get_dec_hh_length(t_ftprintf *t)
{
	return ((long long int)(char)va_arg(t->ap, int));
}

long long int	get_dec_h_length(t_ftprintf *t)
{
	return ((long long int)(short)va_arg(t->ap, int));
}

long long int	get_dec_l_length(t_ftprintf *t)
{
	return ((long long int)va_arg(t->ap, long int));
}

long long int	get_dec_ll_length(t_ftprintf *t)
{
	return ((long long int)va_arg(t->ap, long long int));
}
