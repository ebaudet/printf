/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:55:04 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/28 17:59:10 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

t_hadler_case	*put_handler(char format)
{
	static t_handler	(handler[10]) = {
		{.value = 'c', .handle = put_c},
		{.value = 's', .handle = put_s},
		{.value = 'p', .handle = put_p},
		{.value = 'd', .handle = put_d},
		{.value = 'i', .handle = put_d},
		{.value = 'o', .handle = put_o},
		{.value = 'u', .handle = put_u},
		{.value = 'x', .handle = put_x},
		{.value = 'X', .handle = put_x_cap},
		{.value = 'f', .handle = put_f},
	};
	int					i;

	i = -1;
	while (++i < 10) {
		if (format == handler[i].value)
			return &handler[i].handle;
	}
	return NULL;
}

int			flag_handler(char format, int flag)
{
	if (format == '-')
		flag |= MINUS;
	else if (format == '+')
		flag |= PLUS;
	else if (format == ' ')
		flag |= SPACE;
	else if (format == '0')
		flag |= ZERO;
	else if (format == '#')
		flag |= HASH;
	return flag;
}

int 	length_handler(char *format, t_ftprintf *t)
{
	if (format[0] == 'h') {
		if (format[1] && format[1] == 'h' && t->i++)
			return HH;
		return H;
	}
	else if (format[0] == 'l')
	{
		if (format[1] && format[1] == 'l' && t->i++)
			return LL;
		return L;
	}
	else if (format[0] == 'L')
		return LD;
	else if (format[0] == 'z')
		return Z;
	else if (format[0] == 't')
		return T;
	return NONE_LENGH;
}

int		precision_handler(char *format, t_ftprintf *t)
{
	char	*last_position_number;
	char	number[26];

	if (format[t->i] != '.')
		return 0;
	t->i++;
	if (format[t->i] != '*')
		return va_arg(t->ap, unsigned int);
	last_position_number = find_last_nunber(&format[t->i]);
	if (last_position_number == &format[t->i])
		return 0;
	ft_strncpy(number, &format[t->i], last_position_number - &format[t->i]);
	return ft_atoi(number);
}
