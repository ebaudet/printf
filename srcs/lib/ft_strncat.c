/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:51:41 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:59:06 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		lenght;

	lenght = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[i + lenght] = s2[i];
		i++;
	}
	s1[i + lenght] = 0;
	return (s1);
}
