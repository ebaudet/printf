/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/23 22:15:09 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"


static t_hadler_case	*put_handler(char format)
{
	static t_handler	(handler[10]) = {
		{.conversion = 'c', .handle = put_c},
		{.conversion = 's', .handle = put_s},
		{.conversion = 'p', .handle = put_p},
		{.conversion = 'd', .handle = put_d},
		{.conversion = 'i', .handle = put_d},
		{.conversion = 'o', .handle = put_o},
		{.conversion = 'u', .handle = put_u},
		{.conversion = 'x', .handle = put_x},
		{.conversion = 'X', .handle = put_x_cap},
		{.conversion = 'f', .handle = put_f},
	};
	int					i;

	i = -1;
	while (++i < 10) {
		if (format == handler[i].conversion)
			return &handler[i].handle;
	}
	return NULL;
}

static char	*is_arg(t_ftprintf *t, char *format)
{
	char			buf[256];
	t_hadler_case	*handler;

	ft_memset(buf, 0, 256);
	if (format[t->i] == '%')
	{
		t->i += 1;
		if (!format[t->i])
			return (ft_strdup(ft_strncat(buf, "%", 1)));
		else if (format[t->i] == '%')
			print_uniq_caract(t, format, buf);
		else if (ft_strchr("-+ 0#", format[t->i]) != NULL)
			return (ft_strdup(ft_strncat(buf, "%", 1))); // @TODO: handle it
		else if ((handler = put_handler(format[t->i])) != NULL)
			(*handler)(t, buf);
		else
			return (ft_strdup(ft_strncat(buf, "%", 1)));
		t->i += 1;
		return (ft_strdup(buf));
	}
	return (NULL);
}

static char	*print_caract(t_ftprintf *t, char *format)
{
	char	buf[256];
	char	*tmp;

	ft_memset(buf, 0, 256);
	while (format[t->i])
	{
		tmp = is_arg(t, format);
		if (tmp != NULL)
		{
			ft_strcat(buf, tmp);
			free(tmp);
			break;
		}
		ft_strncat(buf, format + t->i, 1);
		t->i += 1;
	}
	return ft_strdup(buf);
}

char		*ft_getsstr(t_ftprintf *t, const char *format)
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
	char 		*str;

	va_start(t.ap, format);
	str = ft_getsstr(&t, format);
	va_end(t.ap);
	return str;
}

int			ft_printf(const char *format, ...)
{
	t_ftprintf	t;
	char 		*str;
	int			length;

	va_start(t.ap, format);
	str = ft_getsstr(&t, format);
	va_end(t.ap);
	length = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return length;
}

