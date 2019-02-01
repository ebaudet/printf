/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_lenght.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:10:50 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/01 00:30:34 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	get_signed_int_handler(t_ftprintf *t, t_length length)
{
	static t_handler_len	(handler[4]) = {
		{.value = HH, .handle = get_signed_hh_length},
		{.value = H, .handle = get_signed_h_length},
		{.value = L, .handle = get_signed_l_length},
		{.value = LL, .handle = get_signed_ll_length},
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

long long int	get_signed_hh_length(t_ftprintf *t)
{
	return ((char)va_arg(t->ap, int));
}

long long int	get_signed_h_length(t_ftprintf *t)
{
	return ((short)va_arg(t->ap, int));
}

long long int	get_signed_l_length(t_ftprintf *t)
{
	return (va_arg(t->ap, long int));
}

long long int	get_signed_ll_length(t_ftprintf *t)
{
	return (va_arg(t->ap, long long int));
}


long long unsigned int	get_unsigned_int_handler(t_ftprintf *t, t_length length)
{
	static t_handler_lenu	(handler[4]) = {
		{.value = HH, .handle = get_uns_hh_length},
		{.value = H, .handle = get_uns_h_length},
		{.value = L, .handle = get_uns_l_length},
		{.value = LL, .handle = get_uns_ll_length},
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

long long unsigned int	get_uns_hh_length(t_ftprintf *t)
{
	return ((char)va_arg(t->ap, unsigned int));
}

long long unsigned int	get_uns_h_length(t_ftprintf *t)
{
	return ((short)va_arg(t->ap, unsigned int));
}

long long unsigned int	get_uns_l_length(t_ftprintf *t)
{
	return (va_arg(t->ap, long unsigned int));
}

long long unsigned int	get_uns_ll_length(t_ftprintf *t)
{
	return (va_arg(t->ap, long long unsigned int));
}