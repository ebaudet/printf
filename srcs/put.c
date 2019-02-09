/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:02:09 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/08 21:48:07 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static void	precision(char *str, int precision)
{
	int		len;
	char	tmp[BUFF_PARAMS];
	int		i;

	ft_memset(tmp, 0, BUFF_PARAMS);
	if (precision < 0)
		return ;
	len = ft_strlen(str);
	if (len > precision)
	{
		i = 0;
		while (str[i] == '0' && (len - i) >= precision)
			i++;
		ft_strcpy(tmp, str + i);
	}
	else
	{
		ft_memset(tmp, '0', precision - len);
		ft_strcpy(tmp + precision - len, str);
	}
	ft_strclr(str);
	ft_strcpy(str, tmp);
}

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
		return ;
	}
	params->size = params->width;
	if (check_flag(params, MINUS))
	{
		params->buf[0] = c;
		ft_memset(&params->buf[1], check_flag(params, ZERO) ? '0' : ' ',
		          params->width - 1);
	}
	else
	{
		ft_memset(params->buf, check_flag(params, ZERO) ? '0' : ' ',
		          params->width - 1);
		params->buf[params->width - 1] = c;
	}
}

int		add_to_buff(t_params *params, char *str, int len)
{
	char	*tmp;

	len = (len >= 0) ? len : ft_strlen(str);
	if ((params->size + len) >= BUFF_PARAMS)
	{
		tmp = ft_memalloc((params->size + len + 1) * sizeof(char));
		if (params->size >= BUFF_PARAMS)
		{
			ft_strncpy(tmp, params->buf_extra, params->size);
			ft_memdel((void **)&(params->buf_extra));
		}
		else if (params->size > 0)
			ft_strncpy(tmp, params->buf, params->size);
		ft_strncpy(tmp + params->size, str, len);
		params->buf_extra = tmp;
	}
	else
		ft_strncpy(params->buf, str, len);
	params->size += len;
	return (params->size);
}

void	type_s(t_ftprintf *t, t_params *params)
{
	char	*str;

	str = va_arg(t->ap, char *);
	if (str == NULL)
		add_to_buff(params, "(null)", -1);
	else
		add_to_buff(params, str, params->precision);
	fill_string(params->buf, check_flag(params, ZERO) ? '0' : ' ',
		params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
}

void	type_p(t_ftprintf *t, t_params *params)
{
	char	*str;

	str = ft_lutohex(va_arg(t->ap, long unsigned int));
	ft_strcat(params->buf, "0x");
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
	if (check_flag(params, PLUS) && (value >= 0))
		ft_strcat(params->buf, "+");
	if (!check_flag(params, PLUS) && check_flag(params, SPACE) && (value >= 0))
		ft_strcat(params->buf, " ");
	ft_strcat(params->buf, str);
	if (ft_strchr(" +-", params->buf[0]))
		precision(&params->buf[1], params->precision);
	else
		precision(params->buf, params->precision);
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, ft_min(params->width, params->precision));
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_o(t_ftprintf *t, t_params *params)
{
	char					*str;
	unsigned long long int	value;

	value = (params->length == 0)
		? va_arg(t->ap, unsigned long long int)
		: (unsigned long long int)get_signed_int_handler(t, params->length);
	str = ft_lutooct(value);
	if (check_flag(params, HASH))
	{
		ft_strcat(params->buf, "0");
		ft_strcat(&params->buf[1], str);
		precision(&params->buf[1], params->precision);
	}
	else
	{
		ft_strcat(params->buf, str);
		precision(params->buf, params->precision);
	}
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, ft_min(params->width, params->precision));
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_b(t_ftprintf *t, t_params *params)
{
	char			*str;
	long long int	value;

	value = (params->length == 0)
		? va_arg(t->ap, long long int)
		: (long long int)get_signed_int_handler(t, params->length);
	str = ft_lutobin(value);
	if (check_flag(params, HASH))
	{
		ft_strcat(params->buf, "b");
		ft_strcat(&params->buf[1], str);
		precision(&params->buf[1], params->precision);
	}
	else
	{
		ft_strcat(params->buf, str);
		precision(params->buf, params->precision);
	}
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, ft_min(params->width, params->precision));
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_u(t_ftprintf *t, t_params *params)
{
	char		*str;
	uintmax_t	value;

	value = (params->length == 0)
		? va_arg(t->ap, unsigned int)
		: get_usigned_int_handler(t, params->length);
	str = ft_itoa(value);
	ft_strcat(params->buf, str);
	precision(params->buf, params->precision);
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, ft_min(params->width, params->precision));
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
		: get_usigned_int_handler(t, params->length);
	str = ft_lutohex(value);
	if ((value != 0) && check_flag(params, HASH))
	{
		ft_strcat(params->buf, "0x");
		ft_strcat(&params->buf[2], str);
		precision(&params->buf[2], params->precision);
	}
	else
	{
		ft_strcat(params->buf, str);
		precision(params->buf, params->precision);
	}
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, ft_min(params->width, params->precision));
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

void	type_x_cap(t_ftprintf *t, t_params *params)
{
	int	i;

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
	if (check_flag(params, PLUS) && (value > 0))
		ft_strcat(params->buf, "+");
	if (!check_flag(params, PLUS) && check_flag(params, SPACE) && (value > 0))
		ft_strcat(params->buf, " ");
	ft_strcat(params->buf, str);
	if (check_flag(params, ZERO) && !check_flag(params, MINUS))
		fill_zero(params->buf, params->width);
	fill_string(params->buf, ' ', params->width, check_flag(params, MINUS));
	params->size += ft_strlen(params->buf);
	free(str);
}

/*
** Option for color : k
** - width define the color code. Between 0 and 255.
**   <K_BLACK, K_RED, K_GREEN, K_YELLOW, K_BLUE, K_ROSE, K_CYAN, K_WHITE>
** - MINUS flag for underline (;4)
** - PLUS flag for bold (;1)
** - HASH flag for backgroud-color (7 ou +10)
** - ZERO flag for italic (;3)
** - No flags and width define an End of color. (\e[0m)
*/

void	type_k(t_ftprintf *t, t_params *params)
{
	char	*str;
	int		have_flag;

	t->size = t->size;
	have_flag = 0;
	ft_strcat(params->buf, "\e[");
	if (params->width && ++have_flag)
	{
		params->width += check_flag(params, HASH) ? 10 : 0;
		str = ft_itoa(params->width);
		ft_strcat(params->buf, str);
		free(str);
	}
	else if (check_flag(params, HASH) && ++have_flag)
		ft_strcat(params->buf, "7");
	if (check_flag(params, PLUS) && ++have_flag)
		ft_strcat(params->buf, ";1");
	else if (check_flag(params, ZERO) && ++have_flag)
		ft_strcat(params->buf, ";3");
	else if (check_flag(params, MINUS) && ++have_flag)
		ft_strcat(params->buf, ";4");
	if (!have_flag)
		ft_strcat(params->buf, "0");
	ft_strcat(params->buf, "m");
	params->size += ft_strlen(params->buf);
}
