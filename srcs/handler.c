/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:55:04 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:36:02 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		call_handler(char *format, t_ftprintf *t, t_params *params)
{
	static t_call_handler	(handler[5]) = {
		{.value = "-+ 0#", .handle = flag_handler},
		{.value = "123456789", .handle = width_handler},
		{.value = ".", .handle = precision_handler},
		{.value = "hhlLzjt", .handle = length_handler},
		{.value = "cspdiouxXf", .handle = type_handler},
	};
	int						i;
	int						do_stuff;

	do_stuff = 0;
	i = -1;
	while (++i < 5)
	{
		if (ft_strchr(handler[i].value, format[t->i]))
		{
			(handler[i].handle)(&format[t->i], t, params);
			do_stuff++;
			if (i == 4)
				return (-1);
		}
	}
	return (do_stuff);
}

void	flag_handler(char *format, t_ftprintf *t, t_params *params)
{
	if (format[0] == '-')
		params->flag |= MINUS;
	else if (format[0] == '+')
		params->flag |= PLUS;
	else if (format[0] == ' ')
		params->flag |= SPACE;
	else if (format[0] == '0')
		params->flag |= ZERO;
	else if (format[0] == '#')
		params->flag |= HASH;
	else
		return ;
	t->i++;
}

void	width_handler(char *format, t_ftprintf *t, t_params *params)
{
	char	*last_number;
	char	number[26];

	if (format[0] == '*' && ++t->i)
	{
		params->width = va_arg(t->ap, unsigned int);
		return ;
	}
	last_number = find_last_nunber(format);
	if (last_number == format)
	{
		params->width = 0;
		return ;
	}
	ft_strncpy(number, format, last_number - format);
	t->i += last_number - format;
	params->width = ft_atoi(number);
}

void	precision_handler(char *format, t_ftprintf *t, t_params *params)
{
	char	*last_number;
	char	number[26];

	ft_memset(number, 0, 26);
	if (format[0] != '.')
	{
		params->precision = 0;
		return ;
	}
	else if (format[1] && format[1] == '*')
	{
		params->precision = va_arg(t->ap, unsigned int);
		t->i += 2;
		return ;
	}
	last_number = find_last_nunber(&format[1]);
	if (last_number == format)
	{
		params->precision = 0;
		return ;
	}
	ft_strncpy(number, &format[1], last_number - &format[1]);
	t->i += last_number - format;
	params->precision = ft_atoi(number);
}

void	length_handler(char *format, t_ftprintf *t, t_params *params)
{
	if (format[0] == 'h')
	{
		if (format[1] && format[1] == 'h' && t->i++)
			params->length = HH;
		else
			params->length = H;
	}
	else if (format[0] == 'l')
	{
		if (format[1] && format[1] == 'l' && t->i++)
			params->length = LL;
		else
			params->length = L;
	}
	else if (format[0] == 'L')
		params->length = LD;
	else if (format[0] == 'z')
		params->length = Z;
	else if (format[0] == 't')
		params->length = T;
	params->length = NONE_LENGH;
	t->i++;
}

void	type_handler(char *format, t_ftprintf *t, t_params *params)
{
	static t_handler	(handler[10]) = {
		{.value = 'c', .handle = type_c},
		{.value = 's', .handle = type_s},
		{.value = 'p', .handle = type_p},
		{.value = 'd', .handle = type_d},
		{.value = 'i', .handle = type_d},
		{.value = 'o', .handle = type_o},
		{.value = 'u', .handle = type_u},
		{.value = 'x', .handle = type_x},
		{.value = 'X', .handle = type_x_cap},
		{.value = 'f', .handle = type_f},
	};
	int					i;

	i = -1;
	while (++i < 10)
	{
		if (format[0] == handler[i].value)
		{
			(*handler[i].handle)(t, t->buf, params);
			t->i++;
			return ;
		}
	}
}
