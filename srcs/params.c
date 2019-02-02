/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:00:30 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/02 19:12:46 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

t_params	*params_reset(t_params *params)
{
	ft_memset(params, 0, sizeof(*params));
	params->precision = -1;
	ft_memset(params->buf, 0, BUFF_PARAMS);
	return (params);
}
