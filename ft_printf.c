/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/27 16:53:24 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"


static t_hadler_case	*put_handler(char format)
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

/*
* This function search the first occurance of one of the caraters of needle in
* heystack.
*/
char *ft_strstrchr(const char *haystack, const char *needle)
{
	while (*haystack && ft_strchr(needle, haystack[0]) == NULL)
		haystack++;
	if (!*haystack)
		return (NULL);
	else
		return ((char *)haystack);
}

static char	*is_arg(t_ftprintf *t, char *format, t_params *params)
{
	char			buf[256];
	char			*next_modulo;
	char			*end_arg;

	ft_memset(buf, 0, 256);
	if (format[t->i] == '%')
	{
		t->i += 1;
		if (!format[t->i])
			return (ft_strdup(ft_strncat(buf, "%", 1)));
		next_modulo = ft_strchr(&format[t->i], '%');
		end_arg = ft_strstrchr(&format[t->i], "cspdiouxXf");
		if (next_modulo != NULL && end_arg != NULL && next_modulo < end_arg) {
			print_uniq_caract(t, format, buf, (int)(format - next_modulo));
			t->i += (int)(format - next_modulo);
			// todo: checker here to print correctly %bla% => %
		}
		else if (ft_strchr("-+ 0#", format[t->i]) != NULL)
			params->flag = flag_handler(format[t->i], params->flag);
		else if (ft_strchr("hhlLzjt", format[t->i]) != NULL)
			params->length = length_handler(&format[t->i], t);
		else if (ft_strchr("cspdiouxXf", format[t->i]) != NULL) {
			params->type = put_handler(format[t->i]);
			// how to call it : (*(params->type))(t, buf);
			(*(params->type))(t, buf, params);
			ft_memset(params, 0, sizeof(params));
		}
		else
			return (ft_strdup(ft_strncat(buf, "%", 1)));
		t->i += 1;
		return (ft_strdup(buf));
	}
	return (NULL);
}

static char	*print_caract(t_ftprintf *t, char *format)
{
	char		buf[256];
	char		*tmp;
	t_params	params;

	ft_memset(&params, 0, sizeof(params));
	ft_memset(buf, 0, 256);
	while (format[t->i])
	{
		tmp = is_arg(t, format, &params);
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

