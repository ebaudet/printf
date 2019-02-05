/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:00:30 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/05 19:28:48 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

t_params	*params_reset(t_params *params)
{
	ft_memset(params, 0, sizeof(*params));
	params->precision = -1;
	params->width = 0;
	ft_memset(params->buf, 0, BUFF_PARAMS);
	return (params);
}
