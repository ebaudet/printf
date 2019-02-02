/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/03 00:09:32 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdio.h>

int		is_arg(t_ftprintf *t, const char *format, t_params *params)
{
	char			*next_modulo;
	char			*end_arg;

	if (format[t->i] == '%' && ++(t->i))
	{
		if (!format[t->i])
		{
			ft_strncat(params->buf, "%", 1);
			params->size = 1;
			return (1);
		}
		next_modulo = ft_strchr(&format[t->i], '%');
		end_arg = ft_strstrchr(&format[t->i], P_TYPE);
		if (end_arg == NULL && next_modulo == NULL)
		{
			ft_strncat(params->buf, "[FORMAT ERROR]", 14);
			params->size = 14;
			return (1);
		}
		while (format[t->i] && call_handler(format, t, params) > 0)
			;
		return (1);
	}
	return (0);
}

void	ft_concat_param(t_ftprintf *t, t_params *params)
{
	char	*tmp;

	tmp = ft_memalloc(t->size + params->size);
	ft_memcpy(tmp, t->str, t->size);
	ft_memcpy(tmp + t->size, params->buf, params->size);
	free(t->str);
	t->size += params->size;
	t->str = tmp;
}

static char	*ft_getsstr(t_ftprintf *t, const char *format)
{
	t_params	params;

	params_reset(&params);
	t->str = ft_memalloc(1);
	t->i = 0;
	while (format[t->i] != '\0')
	{
		if (!is_arg(t, format, &params))
		{
			params.buf[0] = format[t->i];
			params.size = 1;
			t->i++;
		}
		ft_concat_param(t, &params);
		params_reset(&params);
	}
	return (t->str);
}

t_ftsprintf		*ft_sprintf(const char *format, ...)
{
	t_ftprintf	t;
	char		*str;
	t_ftsprintf	*out;

	t.size = 0;
	va_start(t.ap, format);
	str = ft_getsstr(&t, format);
	va_end(t.ap);
	out = ft_memalloc(sizeof(*out));
	out->len = t.size;
	out->str = t.str;
	return (out);
}

int			ft_printf(const char *format, ...)
{
	t_ftprintf	t;

	t.size = 0;
	va_start(t.ap, format);
	ft_getsstr(&t, format);
	va_end(t.ap);
	write(1, t.str, t.size);
	free(t.str);
	return (t.size);
}
