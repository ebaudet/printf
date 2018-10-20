/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/21 20:45:55 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static void	print_uniq_caract(t_ftprintf *t, char *format, char *buf)
{
	ft_strncat(buf, format + t->i, 1);
	t->i = t->i + 1;
}

static void	print_p(t_ftprintf *t, char *buf)
{
	char 	*str;

	str = ft_lutohex(va_arg(t->ap, long unsigned int));
	ft_strcat(buf, str);
	free(str);
}

static void	print_c(t_ftprintf *t, char *buf)
{
	char	c;

	c = (char)(va_arg(t->ap, int));
	ft_strncat(buf, &c, 1);
	t->i += 1;
}

static void	print_s(t_ftprintf *t, char *buf)
{
	char	*str;

	str = ft_strdup(va_arg(t->ap, char *));
	ft_strcat(buf, str);
	free(str);
}

static void	print_d(t_ftprintf *t, char *buf)
{
	char	*str;

	str = ft_itoa(va_arg(t->ap, int));
	ft_strcat(buf, str);
	free(str);
}

static char	*is_arg(t_ftprintf *t, char *format)
{
	char	buf[256];

	ft_memset(buf, 0, 256);
	if (format[t->i] == '%')
	{
		t->i += 1;
		if (!format[t->i])
			return (ft_strdup(ft_strncat(buf, "%", 1)));
		else if (format[t->i] == '%')
			print_uniq_caract(t, format, buf);
		else if (format[t->i] == 'd' || format[t->i] == 'i'
			|| format[t->i] == 'u')
			print_d(t, buf);
		else if (format[t->i] == 's')
			print_s(t, buf);
		else if (format[t->i] == 'c')
			print_c(t, buf);
		else if (format[t->i] == 'p')
			print_p(t, buf);
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
		// @todo : pweokfwfe
		ft_strncat(buf, format + t->i, 1);

		t->i += 1;
	}
	return ft_strdup(buf);
}

char	*ft_getsstr(t_ftprintf *t, const char *format)
{
	char			*str;
	char			*tmp;
	char			*buf;

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


char	*ft_sprintf(const char *format, ...)
{
	t_ftprintf	t;
	char 		*str;

	va_start(t.ap, format);
	str = ft_getsstr(&t, format);
	va_end(t.ap);
	return str;
}

int		ft_printf(const char *format, ...)
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

