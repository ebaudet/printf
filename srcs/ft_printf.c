/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/01 18:08:04 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdio.h>

static char	*is_arg(t_ftprintf *t, char *format, t_params *params)
{
	char			buf[256];
	char			*next_modulo;
	char			*end_arg;

	ft_memset(buf, 0, 256);
	t->buf = buf;
	if (format[t->i] == '%' && ++(t->i))
	{
		if (!format[t->i])
			return (ft_strdup(ft_strncat(buf, "%", 1)));
		next_modulo = ft_strchr(&format[t->i], '%');
		end_arg = ft_strstrchr(&format[t->i], "cspdiouxXf");
		if (end_arg == NULL && next_modulo == NULL)
			return (ft_strdup(ft_strncat(buf, "[FORMAT ERROR]", 14)));
		while (format[t->i] && call_handler(format, t, params) > 0)
			;
		return (ft_strdup(buf));
	}
	return (NULL);
}

static char	*print_caract(t_ftprintf *t, char *format)
{
	char		buf[256];
	char		*tmp;
	t_params	params;

	params_init(&params);
	ft_memset(buf, 0, 256);
	while (format[t->i])
	{
		tmp = is_arg(t, format, &params);
		if (tmp != NULL)
		{
			ft_strcat(buf, tmp);
			free(tmp);
			break ;
		}
		ft_strncat(buf, format + t->i, 1);
		t->i += 1;
	}
	return (ft_strdup(buf));
}

static char		*ft_getsstr(t_ftprintf *t, const char *format)
{
	char	*str;
	char	*tmp;
	char	*buf;

	str = ft_memalloc(1);
	t->i = 0;
	while (format[t->i] != '\0')
	{
		tmp = print_caract(t, (char *)format);
		buf = ft_strjoin(str, tmp);
		free(str);
		free(tmp);
		str = buf;
	}
	return (str);
}

char		*ft_sprintf(const char *format, ...)
{
	t_ftprintf	t;
	char		*str;

	va_start(t.ap, format);
	str = ft_getsstr(&t, format);
	va_end(t.ap);
	return (str);
}

int			ft_printf(const char *format, ...)
{
	t_ftprintf	t;
	char		*str;
	int			length;

	va_start(t.ap, format);
	str = ft_getsstr(&t, format);
	va_end(t.ap);
	length = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (length);
}
