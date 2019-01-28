/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:55:04 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/28 22:32:39 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int				call_handler(char *format, t_ftprintf *t, t_params *params)
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
			ft_putstr("__");
			ft_putchar(format[t->i]);
			ft_putchar('|');
			ft_putstr(handler[i].value);
			ft_putstr("__");
			(handler[i].handle)(&format[t->i], t, params);
			do_stuff++;
			if (i == 4)
				return (-1);
		}
	}
	return (do_stuff);
}

void			flag_handler(char *format, t_ftprintf *t, t_params *params)
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

void			width_handler(char *format, t_ftprintf *t, t_params *params)
{
	char	*last_number;
	char	number[26];

	if (format[t->i] == '*' && ++t->i)
	{
		params->width = va_arg(t->ap, unsigned int);
		return ;
	}
	last_number = find_last_nunber(&format[t->i]);
	if (last_number == &format[t->i])
	{
		params->width = 0;
		return ;
	}
	ft_strncpy(number, &format[t->i], last_number - &format[t->i]);
	t->i += last_number - &format[t->i];
	params->width = ft_atoi(number);
}

void			precision_handler(char *format, t_ftprintf *t, t_params *params)
{
	char	*last_number;
	char	number[26];

	if (format[t->i] != '.')
	{
		params->precision = 0;
		return ;
	}
	else if (format[++t->i] == '*' && ++t->i)
	{
		params->precision = va_arg(t->ap, unsigned int);
		return ;
	}
	last_number = find_last_nunber(&format[t->i]);
	if (last_number == &format[t->i])
	{
		params->precision = 0;
		return ;
	}
	ft_strncpy(number, &format[t->i], last_number - &format[t->i]);
	t->i += last_number - &format[t->i];
	params->precision = ft_atoi(number);
}

void			length_handler(char *format, t_ftprintf *t, t_params *params)
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

	ft_putstr("~~");
	ft_putstr(format);
	ft_putstr("~~");

	i = -1;
	while (++i < 10)
	{
		if (format[0] == handler[i].value)
		{
			ft_putchar('\'');
			ft_putchar(handler[i].value);
			ft_putchar('\'');
			(*handler[i].handle)(t, t->buf, params);
			// params->type = &handler[i].handle;
			t->i++;
			return ;
		}
	}
}
