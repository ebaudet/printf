/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:00:30 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/30 23:17:08 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

t_params	*params_init(t_params *params)
{
	ft_memset(params, 0, sizeof(*params));
	params->precision = -1;
	return (params);
}
