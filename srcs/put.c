/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:02:09 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/02 21:50:35 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	type_c(t_ftprintf *t, t_params *params)
{
	char	c;

	if (params)
		params->size = params->size;
	c = (char)(va_arg(t->ap, int));
	if (params->width <= 0)
	{
		params->buf[0] = c;
		params->size = 1;
		return;
	}
	params->size = params->width;
	if (check_flag(params, MINUS))
	{
		params->buf[0] = c;
		ft_memset(&params->buf[1], ' ', params->width - 1);
	}
	else
	{
		ft_memset(params->buf, ' ', params->width - 1);
		params->buf[params->width - 1] = c;
	}
}

void	type_s(t_ftprintf *t, t_params *params)
{
	char	*str;

	str = va_arg(t->ap, char *);
	if (str == NULL)
		ft_strcat(params->buf, "(null)");
	else
	{
		if (params->precision >= 0)
			ft_strncpy(params->buf, str, params->precision);
		else
			ft_strcpy(params->buf, str);
	}
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
}

void	type_p(t_ftprintf *t, t_params *params)
{
	char	*str;

	str = ft_lutohex(va_arg(t->ap, long unsigned int));
	ft_strcat(params->buf, str);
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_d(t_ftprintf *t, t_params *params)
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
			ft_strcat(params->buf, "+");
	}
	else if (check_flag(params, SPACE))
		if (value > 0)
			ft_strcat(params->buf, " ");
	ft_strcat(params->buf, str);
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, params->width);
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_o(t_ftprintf *t, t_params *params)
{
	char	*str;

	if (params->length)
		str = ft_lutooct((long unsigned int)get_signed_int_handler(t,
			params->length));
	else
		str = ft_lutooct(va_arg(t->ap, long unsigned int));
	if (check_flag(params, HASH))
		ft_strcat(params->buf, str);
	else
		ft_strcat(params->buf, str + 1 * sizeof(char));
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, params->width);
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_u(t_ftprintf *t, t_params *params)
{
	char					*str;
	unsigned long long int	value;

	value = (params->length == 0)
		? va_arg(t->ap, unsigned int)
		: get_signed_int_handler(t, params->length);
	str = ft_itoa(value);
	ft_strcat(params->buf, str);
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_x(t_ftprintf *t, t_params *params)
{
	char			*str;
	long long int	value;

	value = (params->length == 0)
		? va_arg(t->ap, unsigned int)
		: get_signed_int_handler(t, params->length);
	str = ft_lutohex(value);
	if (params->precision == 0 && ft_strcmp("0", str))
		str[0] = '\0';
	// ft_strcat(params->buf, str);
	// params->buf = fill_string(buf, '0', params->precision, 0);
	if ((value != 0) && check_flag(params, HASH))
		ft_strcat(params->buf, "0x");
	ft_strcat(params->buf, str);
	// precision part :
	// si presion == 0 -> supprime tous les 0 avant X

	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, params->width);
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_x_cap(t_ftprintf *t, t_params *params)
{
	int		i;

	type_x(t, params);
	i = -1;
	while (params->buf[++i] != 0)
		params->buf[i] = ft_toupper(params->buf[i]);
}

void	type_f(t_ftprintf *t, t_params *params)
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
			ft_strcat(params->buf, "+");
	}
	else if (check_flag(params, SPACE))
	{
		if (value > 0)
			ft_strcat(params->buf, " ");
	}
	ft_strcat(params->buf, str);
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, params->width);
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}
