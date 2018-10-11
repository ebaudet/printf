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

//================ For test ONLY ===============================================
void	ft_putstr(char const *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i] != 0)
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}
//==============================================================================


void	print_c(t_data *t)
{
	char	c;

	c = (char)(va_arg(t->ap, int));
	ft_putchar(c);
	t->count += 1;
	t->i += 1;
}

void	print_s(t_data *t)
{
	char	*str;

	str = ft_strdup(va_arg(t->ap, char *));
	putstr_count(t, str);
	free(str);
}

void	print_d(t_data *t)
{
	char	*str;

	str = ft_itoa(va_arg(t->ap, int));
	putstr_count(t, str);
	free(str);
}

void	putstr_count(t_data *t, char *str)
{
	int		size;

	size = ft_strlen(str);
	write(1, str, size);
	t->count += size;
}

int		is_arg(t_data *t, char *format)
{
	if (format[t->i] == '%')
	{
		t->i += 1;
		if (!format[t->i])
			return (1);
		else if (format[t->i] == '%')
			print_uniq_caract(t, format);
		else if (format[t->i] == 'd' || format[t->i] == 'i'
			|| format[t->i] == 'u')
			print_d(t);
		else if (format[t->i] == 's')
			print_s(t);
		else if (format[t->i] == 'c')
			print_c(t);
		t->i += 1;
		return (1);
	}
	return (0);
}

void	print_uniq_caract(t_data *t, char *format)
{
	ft_putchar(format[t->i]);
	t->i = t->i + 1;
	t->count = t->count + 1;
}

void	print_caract(t_data *t, char *format)
{

	while (format[t->i] && !is_arg(t, format))
	{
		ft_putchar(format[t->i]);
		t->i += 1;
		t->count += 1;
	}
}

int		ft_printf(const char *format, ...)
{
	t_data		t;

	va_start(t.ap, format);
	t.i = 0;
	t.count = 0;
	while (format[t.i] != '\0')
	{
		print_caract(&t, (char *)format);
	}
	va_end(t.ap);
	return (t.count);
}
