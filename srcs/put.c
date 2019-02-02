/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:02:09 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/02 16:30:25 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	print_uniq_caract(t_ftprintf *t, char *format, char *buf, int size)
{
	ft_strncat(buf, &format[t->i], size);
}

void	type_c(t_ftprintf *t, char *buf, t_params *params)
{
	char	c;

	if (params)
		params->size = params->size;
	c = (char)(va_arg(t->ap, int));
	ft_strncat(buf, &c, 1);
}

void	type_s(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;
	size_t	len;

	str = ft_strdup(va_arg(t->ap, char *));
	len = ft_strlen(str);
	if (params->precision >= 0 && (len > (size_t)params->precision))
		ft_memset(str + params->precision, 0, len - params->precision);
	ft_strcat(buf, str);
	buf = fill_string(buf, ' ', params->width, check_flag(params, MINUS));
	free(str);
}

void	type_p(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	str = ft_lutohex(va_arg(t->ap, long unsigned int));
	ft_strcat(buf, str);
	buf = fill_string(buf, ' ', params->width, check_flag(params, MINUS));
	free(str);
}

void	type_d(t_ftprintf *t, char *buf, t_params *params)
{
	char			*str;
	long long int	value;

	if (params->length)
		value = get_signed_int_handler(t, params->length);
	else
		value = va_arg(t->ap, int);
	str = ft_itoa(value);
	if (check_flag(params, PLUS))
	{
		if (value > 0)
			ft_strcat(buf, "+");
	}
	else if (check_flag(params, SPACE))
		if (value > 0)
			ft_strcat(buf, " ");
	ft_strcat(buf, str);
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		buf = fill_zero(buf, params->width);
	buf = fill_string(buf, ' ', params->width, check_flag(params, MINUS));
	free(str);
}

void	type_o(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	if (params->length)
		str = ft_lutooct((long unsigned int)get_signed_int_handler(t,
			params->length));
	else
		str = ft_lutooct(va_arg(t->ap, long unsigned int));
	if (check_flag(params, HASH))
		ft_strcat(buf, str);
	else
		ft_strcat(buf, str + 1 * sizeof(char));
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		buf = fill_zero(buf, params->width);
	buf = fill_string(buf, ' ', params->width, check_flag(params, MINUS));
	free(str);
}

void	type_u(t_ftprintf *t, char *buf, t_params *params)
{
	char					*str;
	unsigned long long int	value;

	value = (params->length == 0)
		? va_arg(t->ap, unsigned int)
		: get_signed_int_handler(t, params->length);
	str = ft_itoa(value);
	ft_strcat(buf, str);
	buf = fill_string(buf, ' ', params->width, check_flag(params, MINUS));
	free(str);
}

void	type_x(t_ftprintf *t, char *buf, t_params *params)
{
	char			*str;
	long long int	value;

	value = (params->length == 0)
		? va_arg(t->ap, unsigned int)
		: get_signed_int_handler(t, params->length);
	str = ft_lutohex(value);
	if (params->precision == 0 && ft_strcmp("0", str))
		str[0] = '\0';
	// ft_strcat(buf, str);
	// buf = fill_string(buf, '0', params->precision, 0);
	if ((value != 0) && check_flag(params, HASH))
		ft_strcat(buf, "0x");
	ft_strcat(buf, str);
	// precision part :
	// si presion == 0 -> supprime tous les 0 avant X

	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		buf = fill_zero(buf, params->width);
	buf = fill_string(buf, ' ', params->width, check_flag(params, MINUS));
	free(str);
}

void	type_x_cap(t_ftprintf *t, char *buf, t_params *params)
{
	int		i;

	type_x(t, buf, params);
	i = -1;
	while (buf[++i] != 0)
		buf[i] = ft_toupper(buf[i]);
}

void	type_f(t_ftprintf *t, char *buf, t_params *params)
{
	char		*str;
	long double	value;

	if (params->length == L || params->length == LD)
		value = va_arg(t->ap, long double);
	else
		value = va_arg(t->ap, double);
	str = (params->precision == -1)
		? ft_dtoa(value, 6)
		: ft_dtoa(value, params->precision);
	if (check_flag(params, PLUS))
	{
		if (value > 0)
			ft_strcat(buf, "+");
	}
	else if (check_flag(params, SPACE))
	{
		if (value > 0)
			ft_strcat(buf, " ");
	}
	ft_strcat(buf, str);
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		buf = fill_zero(buf, params->width);
	buf = fill_string(buf, ' ', params->width, check_flag(params, MINUS));
	free(str);
}
