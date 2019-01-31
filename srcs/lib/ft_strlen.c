/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:50:59 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:59:04 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	cpt;

	if (!s)
		return (0);
	cpt = 0;
	while (s[cpt] != 0)
		cpt++;
	return (cpt);
}
