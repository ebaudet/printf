/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:02:09 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/30 18:07:35 by ebaudet          ###   ########.fr       */
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

	if (params)
		params->size = params->size;
	str = ft_strdup(va_arg(t->ap, char *));
	ft_strcat(buf, str);
	free(str);
}

void	type_p(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	if (params)
		params->size = params->size;
	str = ft_lutohex(va_arg(t->ap, long unsigned int));
	ft_strcat(buf, str);
	free(str);
}

void	type_d(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	if (params->length)
		str = ft_itoa(get_dec_length_handler(t, params->length));
	else
		str = ft_itoa(va_arg(t->ap, int));
	ft_strcat(buf, str);
	free(str);
}

void	type_u(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	if (params->length)
		str = ft_itoa(get_dec_length_handler(t, params->length));
	else
		str = ft_itoa(va_arg(t->ap, unsigned int));
	ft_strcat(buf, str);
	free(str);
}

void	type_o(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	if (params->length)
		str = ft_lutooct((long unsigned int)get_dec_length_handler
		                 (t, params->length));
	else
		str = ft_lutooct(va_arg(t->ap, long unsigned int));
	ft_strcat(buf, str);
	free(str);
}


void	type_x(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	if (params->length)
		str = ft_lutohex(get_dec_length_handler(t, params->length));
	else
		str = ft_lutohex(va_arg(t->ap, long unsigned int));
	ft_strcat(buf, str + 2 * sizeof(char));
	free(str);
}

void	type_x_cap(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;
	int		i;

	if (params->length)
		str = ft_lutohex(get_dec_length_handler(t, params->length));
	else
		str = ft_lutohex(va_arg(t->ap, long unsigned int));
	i = -1;
	while (str[++i] != 0)
		str[i] = ft_toupper(str[i]);
	ft_strcat(buf, str + 2 * sizeof(char));
	free(str);
}

void	type_f(t_ftprintf *t, char *buf, t_params *params)
{
	char	*str;

	if (params->length == L || params->length == LD)
		str = ft_dtoa(va_arg(t->ap, long double), 6);
	else
		str = ft_dtoa(va_arg(t->ap, double), 6);
	ft_strcat(buf, str);
	free(str);
}
