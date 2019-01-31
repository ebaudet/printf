/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 20:06:57 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strreverse(char *str)
{
	char	tmp;
	int		j;
	int		i;

	j = ft_strlen(str);
	i = -1;
	while (++i < --j)
	{
		tmp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = tmp;
	}
}
